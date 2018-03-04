#include <stdio.h>

void ranges(int x[], int npts, int *max_ptr, int *min_ptr);

int a[] = {1,2,3};
int b[] = {3,17,2,5,4,3,2};
int c[] = {3,2,2,2,2,2};

//this might seem like obfuscated code, but I tried clearing it up and it only resulted
//in an error
int sizes[] = {sizeof(a)/sizeof(a[0]), sizeof(b)/sizeof(b[0]), sizeof(c)/sizeof(c[0])};

int main()  {
	int *full[] = {a,b,c};
	for(int i = 0; i < 3; i++) {			
		int max;
		int min;
		ranges(full[i], sizes[i], &max, &min);
		printf("Min value: %d, Max Value: %d\n", min, max);
	}
	return 0;
}

void ranges(int x[], int npts, int *max_ptr, int *min_ptr) {
	int curMin = x[0];
	int curMax = x[0];
	//min finding
	for(int i = 1; i < npts; i++) {
		if(x[i] < x[i-1]) { //if the current value is smaller than the last
			curMin = x[i];
		}
		else if(x[i] > x[i-1]) { //if the current value is bigger than the last
			curMax = x[i];
		}
	}
	*min_ptr = curMin;
	*max_ptr = curMax;
}
