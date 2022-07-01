#include <stdio.h>

int main (void)
{   
    int a, b;
    printf("a : ");
    scanf("%d", &a);
    do
    {
        if (b <= a) 
            printf("b should be higher than a!\n");
        printf("b : ");
        scanf("%d", &b);
    } while (b - a <= 0);
    printf("b - a is %d.\n", b-a);

    int c;
    int cnt = 0;
    printf("c : ");
    scanf("%d", &c);
    do
    {
        c = c/10;
        printf("%d\n", c);
        cnt += 1;
    } while (c >= 1);
    printf("%d\n", cnt);
    
    return 0;
}