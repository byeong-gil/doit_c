#include <stdio.h>
#include "IntStack.h"

void recur3(int n)
{
    if (n > 0) {
        recur3(n - 1);
        recur3(n - 2);
        printf("%d\n", n);
    }
}

void recur_nr3(int n)
{
    IntStack stk;
    Initialize(&stk, 100);
Top:
    if (n > 0) {
        Push(&stk, n);
        n -= 1;
        goto Top;
    }
    if (!IsEmpty(&stk)) {
        Pop(&stk, &n);
        if (n > 0) {
            n -= 2;
            goto Top;
        }
        printf("%d\n", n);
    }
    Terminate(&stk);
}

int main(void)
{
    int x;
    printf("Enter an integer : ");
    scanf("%d", &x);
    recur3(x);

    return 0;
}