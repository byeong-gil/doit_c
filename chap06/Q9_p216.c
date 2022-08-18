#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
    int i, j;
    for (i = 2; i < n; i++) {
        a[0] = a[i];
        for (j = i; a[j - 1] > a[0]; j--)
            a[j] = a[j - 1];
        a[j] = a[0];
    }
}

int main(void)
{
    int i, nx;
    int *x;

    puts("Insertion sort");
    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx + 1, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i + 1]);
    }

    insertion(x, nx);

    puts("Sorting by ascending order is done.");
    for(i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i + 1, x[i + 1]);
    
    free(x);

    return 0;
}