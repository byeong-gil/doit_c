#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while(0)

void bubble(int a[], int n)
{
    int k = 0, pass = 0, cp = 0, swap = 0, j, i;
    while(k < n -1) {
        printf("pass%d\n", pass);
        pass++;
        int last = n - 1;
        for (j = n - 1; j > k; j--) {
            cp++;
            if (a[j - 1] > a[j]) {
                for (i = 0; i < n; i++) {
                    if (i == j)
                        printf("+%d", a[i]);
                    else
                        printf("%2d", a[i]);
                }
                swap++;
                swap(int, a[j - 1], a[j]);
                last = j;
            } else {
                for (i = 0; i < n; i++) {
                    if (i == j)
                        printf("-%d", a[i]);
                    else
                        printf("%2d", a[i]);
                }
            }
            puts("\n");
        }
        k = last;
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