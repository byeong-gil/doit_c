#include <stdio.h>
#include <stdlib.h>

//---function to compare integers(ascending)---//
int int_cmp(const int *a, const int *b)
{
    if (*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size, 
    int(*compar)(const void *, const void *))
{
    int pl = 0;
    int pr = nmemb-1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if (((int *)base)[pc] == *(int *)key) {
            do {
                pc--;
            } while(((int *)base)[pc] == *(int *)key);
            return &((int *)base)[++pc];
        }
        else if (pc < *(int *)key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while(pl <= pr);
    return NULL;
}

int main(void)
{
    int i, nx, ky;
    int *x;
    int *p;
    puts("Search by using bsearch function");
    printf("number of elements: ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("Enter in ascending order.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for(i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while(x[i] < x[i - 1]);
    }
    printf("searching value: ");
    scanf("%d", &ky);

    //using bsearch
    p = binsearch(&ky,
                x,
                nx,
                sizeof(int),
                (int(*)(const void *, const void *)) int_cmp
                );
    
    if (p == NULL)
        puts("Failed to search.");
    else 
        printf("The first %d is in x[%d].\n", ky, (int) (p - x));
    free(x);

    return 0;
}