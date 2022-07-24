#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

void ary_print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("x[%d] = %d\n", i, a[i]);
    puts("\n");
}

void ary_reverse(int a[], int n)
{
    int i;
    for(i = 0; i < n / 2; i++) {
        printf("swap %d and %d.\n", a[i], a[n-i-1]);
        swap(int, a[i], a[n - i - 1]);
        ary_print(a, n);
    }
}

int main(void)
{
    int i;
    int *x;
    int nx;

    printf("number of components: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("Enter the %d numbers.\n", nx);
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("Now the array is fliped.\n");
    ary_reverse(x, nx);
    puts("Now the flip end");
    free(x);

    return 0;
}