#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y)
{
    IntStack stk;
    Initialize(&stk, 100);
    char a[3] = "ABC";
Top: 
    if (no > 1) {
        Push(&stk, no); Push(&stk, x); Push(&stk, y);
        no -= 1; y = 6 - x - y;
        goto Top;
    }
    printf("Move disk[%d] from column %c to column %c.\n", no, a[x - 1], a[y - 1]);
    if (!IsEmpty(&stk)) {
        Pop(&stk, &y); Pop(&stk, &x); Pop(&stk, &no);
        printf("Move disk[%d] from column %c to column %c.\n", no, a[x - 1], a[y - 1]);
    if (no > 1)
        {
            no -= 1; x = 6 - x - y;
            goto Top;
        }
    }
    Terminate(&stk);
}

int main(void)
{
    int n;
    printf("Hanoid Tower\nNumber of disks: ");
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}