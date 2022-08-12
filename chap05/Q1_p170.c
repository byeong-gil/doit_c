#include <stdio.h>

// Factorial without recursive
int factorial(int n)
{
    int x = n;
    for (;n > 1; n--)
        x *= n - 1;
    return x;
}

int main(void)
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    printf("%d! = %d.\n", x, factorial(x));

    return 0;
}