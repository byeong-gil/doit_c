#include <stdio.h>
#include <stdlib.h>

// Binary search for the element matching key in array a
// with n number of elements
int bin_search(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
    printf("    |");
    for(int i = 0; i < n; i++) {printf(" %d  ", i);}
    printf("\n----+");
    for(int i = 0; i < n; i++) {printf("----");}
    do {
        pc = (pl + pr) / 2;

        // print part
        printf("\n    |");
        for(int i = 1; i < pl; i++) {printf("    ");}
        printf(" <- ");
        for(int i = pl + 1; i < pc; i++) {printf("    ");}
        printf(" +  ");
        for(int i = pc + 1; i < pr; i++) {printf("    ");}
        printf("->\n");
        printf("   %d|", pc);
        for(int i = 0; i < n; i++) {printf(" %d  ", a[i]);}
        printf("\n    |");

        if(a[pc] == key){
            puts("");
            return pc;
        }
        else if(a[pc] < key)
            pl = pc + 1;
        else 
            pr = pc - 1;
    } while(pl <= pr);
    puts("");
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
    idx = bin_search(x, nx, ky);
    if(idx == -1)
        puts("failed to search");
    else   
        printf("%d is in x[%d].\n", ky, idx);
    free(x);

    return 0;
}