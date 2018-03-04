#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXLEN 100000
#define MAXLINE 100000

int getlineMe(char s[], int lim);
int readlines(char *lineptr[], int maxlines);
void writelinesMe(char *lineptr[], int nlines, int totalLines);

char *lineptr[MAXLINE];

int main(int argc, char *argv[])  {
	//int nflag = 0;
	int numlines = 0;
	int c;
	opterr = 0;
	while ((c = getopt (argc, argv, "n:")) != -1) {
		switch (c) {
			case 'n':
				//nflag = 1;
				numlines = atoi(optarg);	
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
		}
	}
	if(numlines < 0) {
		printf("Error: invalid number of lines to print");
	}
	int totalLines = readlines(lineptr, MAXLINE);
	if(totalLines >= 0) {
		writelinesMe(lineptr, numlines, totalLines);
	}
	else {
		printf("Error! No input!");
	}
	return 0;
}

/* getline: read a line into s, return length */
int getlineMe(char s[], int lim) {
	int c, i;
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i]= '\0';
return i;

}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getlineMe(line, MAXLEN)) > 0) {
		if (nlines >= maxlines || (p = malloc(len)) == NULL) {
			return -1;
		}
		
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelinesMe(char *lineptr[], int nlines, int totalLines) {
	for (int i = nlines; i > 0; i--) {
		printf("%s\n", lineptr[totalLines - i]);
	}
}
