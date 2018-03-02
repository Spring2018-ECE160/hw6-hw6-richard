#include <stdio.h>

struct point {
    int x;
    int y;
};

int main()  {
	int a,b,c;
	struct point ans[11];
	printf("Enter values for a, b and c in the form a,b,c. No spaces:");
	scanf("%d,%d,%d", &a, &b, &c);
	while ((getchar()) != '\n');
	for(int i = 0, x = -5; x <=5; x++, i++) {
		ans[i].x = x;
		ans[i].y = (a*x*x) + (b*x) + c;
		printf("Pt #%d is (%d, %d)\n", i+1, ans[i].x, ans[i].y);
	}
	return 0;
}
