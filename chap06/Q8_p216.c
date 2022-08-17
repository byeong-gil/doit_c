#include <stdio.h>
#include <stdlib.h>
//#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void insertion(int a[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++) {
        for (k = 0; k < n; k++) {
            printf("%2d", a[k]);
        }
        puts("");
        int tmp = a[i];
        for (j = i; j > 0 && a[j - 1] > tmp; j--) {
            a[j] = a[j - 1];
        }
        for (k = 0; k < i; k++) {
            if (k < j) {
                printf("  ");
            } else if (k == j) {
                printf("^-");
            } else {
                printf("--");
            }
        }
        if (i == j) {
            printf(" +");
        } else {
            printf("-+");
        }
        puts("");
        a[j] = tmp;
    }
}

int main(void)
{
    int i, nx;
    int *x;

    puts("Insertion sort");
    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    insertion(x, nx);

    puts("Sorting by ascending order is done.");
    for(i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    
    free(x);

    return 0;
}