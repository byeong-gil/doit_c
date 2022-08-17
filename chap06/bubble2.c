#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

int is_sorted(const int a[], int n)
{
    int exchg = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            exchg++;
    }
    return !exchg;
}

void bubble(int a[], int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++) {
        int exchg = 0;
        for (j = n - 1; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(int, a[j - 1], a[j]);
                exchg++;
            }
        }
        if (exchg == 0) break;
    }
}

int main(void)
{
    int i, nx;
    int *x;

    puts("Bubble sort");
    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("is already sorted? : %d\n", is_sorted(x, nx));
    bubble(x, nx);

    puts("Sorting by ascending order is done.");
    for(i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    
    free(x);

    return 0;
}