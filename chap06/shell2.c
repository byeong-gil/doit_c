#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
    int i, j, h;
    int cnt = 0;
    for (h = 1; h < n / 9; h = h * 3 + 1)
        ;
    for (; h > 0; h /= 3) {
        for (i = h; i < n; i++) {
            int tmp = a[i];
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) {
                a [j + h] = a[j];
                cnt++;
            }
            a[j + h] = tmp;
        }
    }
    printf("swap %d times.\n", cnt);
}

int main(void)
{
    int i, nx;
    int *x;

    puts("Shell sort");
    printf("Number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shell(x, nx);

    puts("Sorting by ascending order is done.");
    for(i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    
    free(x);

    return 0;
}