#include <stdio.h>

int max4(int a, int b, int c, int d)
{	
	int max = a;
	if(b > max) max = b;
	if(c > max) max = c;
	if(d > max) max = d;
	return max;
}

int min3(int a, int b, int c)
{
	int min = a;
	if(b < min) min = b;
	if(c < min) min = c;
	return min;
}

int min4(int a, int b, int c, int d)
{
	int min = a;
	if(b < min) min = b;
	if(c < min) min = c;
	if(d < min) min = d;
	return min;
}

int main(void) {
	printf("max4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, max4(4, 3, 2, 1));
	printf("min3(%d, %d, %d) = %d\n", 1, 3, 2, min3(1, 3, 2));
	printf("min4(%d, %d, %d, %d) = %d\n", 4, 3, 2, 1, min4(4, 3, 2, 1));
	return 0;
}