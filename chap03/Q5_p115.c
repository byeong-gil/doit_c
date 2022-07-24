#include <stdio.h>
#include <stdlib.h>

// Binary search for the element matching key in array a
// with n number of elements
int bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if(a[pc] == key)
            return pc;
        else if(a[pc] < key)
            pl = pc + 1;
        else 
            pr = pc - 1;
    } while(pl <= pr);

    return -1;
}

int bin_search2(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if(a[pc] == key) {
            do {
                pc--;
            } while(a[pc] == key);
            return ++pc;
        }
        else if(a[pc] < key)
            pl = pc + 1;
        else 
            pr = pc - 1;
    } while(pl <= pr);

    return -1;
}

int main(void)
{
    int i, nx, ky, idx;
    int *x;
    puts("binary search");
    printf("the number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    printf("Enter the numbers in oascending order.\n");
    printf("x[0]: ");
    scanf("%d", &x[0]);
    for(i = 1; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while(x[i] < x[i - 1]);
    }
    printf("searching value: ");
    scanf("%d", &ky);
    idx = bin_search2(x, nx, ky);
    if(idx == -1)
        puts("failed to search");
    else   
        printf("The first %d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}