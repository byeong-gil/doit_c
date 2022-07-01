#include <stdio.h>

int main(void)
{
    int i, n;
    int sum;
    puts("get a sum of 1 to n");
    printf("value of n : ");
    scanf("%d", &n);
    sum = 0;
    for(i = 1; i < n; i++) {
        printf("%d + ", i);
        sum += i;
    }
    sum += i;
    printf("%d", i);
    printf(" = %d.\n", sum);

    return 0;   
}