#include <stdio.h>

void move(int no, int x, int y)
{
    char a[3] = "ABC";
    if(no > 1) {
        move(no - 1, x, 6 - x - y);
    }
    printf("Move disk[%d] from column %c to column %c.\n", no, a[x - 1], a[y - 1]);
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