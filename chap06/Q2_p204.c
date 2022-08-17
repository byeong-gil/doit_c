#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void bubble(int a[], int n)
{
    int i, j, k;
    int pass = 0, cp = 0, swap = 0;
    for(i = n - 1; i > 0; i--) {
        printf("pass%d:\n", pass);
        pass++;
        for (j = 0; j < i; j++) {
            cp++;
            if (a[j] > a[j + 1]) {
                for (k = 0; k < n; k++) {
                    if (k == j + 1)
                        printf("+%d", a[k]);
                    else
                        printf("%2d", a[k]);
                }
                swap(int, a[j], a[j + 1]);
                swap++;
            } else {
                for (k = 0; k < n; k++) {
                    if (k == j + 1)
                        printf("-%d", a[k]);
                    else
                        printf("%2d", a[k]);
                }
            }
            puts("\n");
        }
    }
    printf("compare %d times, swap %d times.\n", cp, swap);
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