#include <stdio.h>
#include <stdlib.h>

long long_cmpr(const long *a, const long *b)
{
    if (*a < *b)
        return 1;
    else if(*a > *b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int i, nx;
    long ky;
    long *x;
    long *p;
    puts("Search by using bsearch function");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(long));

    printf("Enter in descending order.\n");
    printf("x[0]: ");
    scanf("%ld", &x[0]);
    for(i = 1; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%ld", &x[i]);
        } while(x[i] > x[i - 1]);
        printf("searching value: ");
        scanf("%ld", &ky);
    }

    p = bsearch(&ky,
                x,
                nx,
                sizeof(long),
                (int(*)(const void *, const void *)) long_cmpr
                );
    
    if (p == NULL)
        puts("Failed to search");
    else
        printf("%ld is in x[%d].\n", ky, (int) (p - x));
    free(x);

    return 0;
}