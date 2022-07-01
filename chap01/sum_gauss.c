#include <stdio.h>

int sumof(int a, int b)
{
    if ((b - a) % 2 == 0)
        return (a + b) * (b - a + 1)/2;
    else   
        return (a + b) * (b - a)/2 + (b+a)/2; 
}

int main (void)
{
    int a, b, sum;
    printf("a : ");
    scanf("%d", &a);
    printf("b : ");
    scanf("%d", &b);

    if (a > b)
        sum = sumof(b, a);
    else
        sum = sumof(a, b);

    printf("%d\n", sum);

    return 0;
}