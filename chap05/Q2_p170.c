#include <stdio.h>

// Euclid without using recursive
int gcd(int x, int y)
{
    int gcd = -1;
    while (1) {
        if (x > y) {
            x -= y;
        } else {
            y -= x;
        }
        if (x % y == 0) {
            gcd = y;
            break;
        }
        if (y % x == 0) {
            gcd = x;
            break;
        }
    }
    return gcd;
}

int main(void)
{
    int x, y;
    puts("Get a gcd of two integers.");
    printf("Enter an integer: ");
    scanf("%d", &x);
    printf("Enter an integer: ");
    scanf("%d", &y);
    printf("gcd is %d.\n", gcd(x, y));

    return 0;
}