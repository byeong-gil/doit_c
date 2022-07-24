#include <stdio.h>
#include <stdlib.h>

// linear search(sentinel method) for elements matching keys 
// in array a with n number of elements.
int search(int a[], int n, int key)
{
    int i;
    a[n] = key;
    for(i = 0; i< n; i++) {
        if (a[i] == key)
            break;
    }
    return i == n ? -1 : i;
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("linear search");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx + 1, sizeof(int));
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("searching value: ");
    scanf("%d", &ky);
    idx = search(x, nx, ky);
    if(idx == -1)
        puts("failed to search");
    else   
        printf("%d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}