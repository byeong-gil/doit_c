#include <stdio.h>

int main(void) {
	int a, b, c;
	int max;
	printf("Get a max value in three numbers.\n");
	printf("a : "); scanf("%d", &a);
	printf("b : "); scanf("%d", &b);
	printf("c : "); scanf("%d", &c);
	max = a;
	if(b > max) max = b;
	if(c > max) max = c;

	printf("max numeber is %d\n", max);

	return 0;
}