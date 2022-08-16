#include <stdio.h>

void move(int no, int x, int y)
{
    if(no > 1) {
        move(no - 1, x, 6 - x - y);
    }
    printf("Move dist[%d] from column %d to column %d.\n", no, x, y);
    if (no > 1)
    {
        move(no - 1, 6 - x - y, y);
    }
}

int main(void)
{
    int n;
    printf("Hanoid Tower\nNumber of disks: ");
    scanf("%d", &n);
    move(n, 1, 3);

    return 0;
}