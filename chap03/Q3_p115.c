#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]) 
{
    int count = 0;
    int size = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] == key) {
            size += sizeof(int);
            idx = realloc(idx, size);
            idx[(size / sizeof(int)) - 1] = i;
            count++;
        }        
    }
    return count;
}

int main(void)
{
    int i, nx, ky, num;
    int *x, *idx;
    puts("linear search");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    idx = calloc(0, sizeof(int));
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("searching value: ");
    scanf("%d", &ky);
    num = search_idx(x, nx, ky, idx);
    if(num == -1) {
        puts("failed to search");
    }
    else {
        for(i = 0; i < num; i++)
            printf("idx[%d] = %d\n", i, idx[i]);
    }
    free(x);

    return 0;
}