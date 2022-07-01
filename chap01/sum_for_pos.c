#include <stdio.h>

int main(void)
{
    int i, n;
    int sum;
    puts("get a sum of 1 to n");
    printf("value of n : ");
    do {
        printf("n : ");
        scanf("%d", &n);
    } while(n <= 0);
    sum = 0;
    for(i = 1; i <= n; i++) {
        sum += i;
    }
    printf("sum of the numbers 1 to %d is %d.\n", n, sum);

    return 0;   
}