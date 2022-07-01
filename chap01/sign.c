#include <stdio.h>

int main(void)
{
    int n;

    printf("endter the integer. : ");
    scanf("%d", &n);
    if(n > 0)
        printf("this number is a positive number.\n");
    else if(n < 0)
        printf("this number is a negative number.\n");
    else
        printf("this number is zero.\n");

    //conditional operator test
    int a = 3; int b = 5; int c = 4;
    int d = a == 6 ? a :
            b == 6 ? b : c;
    printf("%d\n", d);

    return 0;
}