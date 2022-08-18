#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bin_search(const int a[], int n, int ky)
{   
    int pl = 0;
    int pr = n - 1;
    int pc;

    do {
        pc = (pl + pr) / 2;
        if (a[pc] == ky) {
            return pc;
        }    
        else if (a[pc] < ky) {
            pl = pc + 1;
        }
        else {
            pr = pc - 1;
        }
    } while(pl <= pr);

    if (pc == n - 1 && ky > a[n - 1]) pc++;
    if (pc == 0 && ky > a[0]) pc++;
    return pc;
}

void insertion(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) {
        int tmp = a[i];
        int lo = bin_search(a, i, tmp);
        for (j = i; j > lo; j--) {
            memmove(&a[j], &a[j - 1], sizeof(int));
        }
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