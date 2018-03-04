#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXLINES 100000
#define ALLOCSIZE 100000


// globals
char *lineptr[MAXLINES]; // pointers to text lines
static char allocbuf[ALLOCSIZE]; // storage for alloc
static char *allocp = allocbuf;  // next free position

// functions
int numcmp(char *s1, char *s2);
int strcmpFold(char *s1, char *s2);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, 
           int (*comp)(void *, void *));

// sort input lines
int main(int argc, char *argv[]) {
    int numeric = 0, fold = 0, reverse = 0;
	int nlines;
	int c;
	opterr = 0;
	while ((c = getopt (argc, argv, "n::f::r::")) != -1) { //n, f, and r are optional
		switch (c) {
			case 'n':
				numeric = 1;	
				break;
			case 'f':
				fold = 1;	
				break;
			case 'r':
				reverse = 1;	
				break;
			case '?':
				if(optopt == 'n') {
					printf("USAGE: %s -n [numlines]\n", argv[0]);
				}
				else if (isprint (optopt))
					printf ("Unknown option %c\n", optopt);
				else
					printf ("Unknown option character %x\n",optopt);
			default:
				printf("USAGE: %s -n [numlines]\n", argv[0]);
				return 1;
		}
	}
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {	
		printf("INPUT:\n");
		writelines(lineptr, nlines);
        qsort((void **) lineptr, 0, nlines-1,
          (int (*)(void*, void*))(numeric ? numcmp : (fold ? strcmpFold : strcmp)));
		if(reverse == 1) {
			for(int i = 0, j = nlines - 1; i < nlines/2 && j > 0; i++, j--) {
				swap(lineptr, i, j);
			}
			printf("\nOUTPUT:\n");
			writelines(lineptr, nlines);
		}
		else {        
			printf("\nOUTPUT:\n");			
			writelines(lineptr, nlines);
		}
		//printf("%lu\n", sizeof(lineptr));
		//printf("%lu\n", strlen(lineptr));
        return 0;
    }
    else 
    {
        printf("input too big to sort\n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000 // max length of any input line
int mygetline(char *, int);
char *alloc(int);

// readlines: read input lines
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0'; // delete newlines
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}



char *alloc(int n) // return pointer to n characters
{
    if (allocbuf + ALLOCSIZE - allocp >= n) // it fits
    {
        allocp += n;
        return allocp - n; // old p
    }
    else // not enough room
        return 0;
}

void afree(char *p) // free storage pointed to by p
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


// mygetline: get line into s, return length
int mygetline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// qsort:sort v[left]...v[right] into increasing order
void qsort(void *v[], int left, int right, 
           int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    // do nothing if array contains fewer than two elements
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

// swap:interchange v[i] and v[j]
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// writelines: write output lines
void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

// compare s1 and s2 numerically
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int strcmpFold(char *s1, char *s2) {
    while(toupper(*s1) == toupper(*s2)) {
        if (*s1 == '\0') {
            return 0;
		}
		s1++, s2++;
	}
    return toupper(*s1) - toupper(*s2);
}
