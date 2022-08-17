#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

// Shaker sort
void bubble(int a[], int n)
{
    int k = 0, pass = 0, last = n- 1, j;
    while(k < n -1) {
        if (pass % 2 == 0) {
            last = n - 1;
            for (j = n - 1; j > k; j--)
                if (a[j - 1] > a[j]) {
                    swap(int, a[j - 1], a[j]);
                    last = j;
                }
            k = last;
        } else {
            last = 0;
            for (j = k + 1; j < n; j++) {
                if (a[j - 1] > a[j]) {
                    swap(int, a[j - 1], a[j]);
                    last = j;
                }
            }
            k = last;
        }
        pass++;
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

    bubble(x, nx);

    puts("Sorting by ascending order is done.");
    for(i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    
    free(x);

    return 0;
}