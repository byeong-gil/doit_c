#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int *a;
    int na;
    printf("number of components : ");
    scanf("%d", &na);
    a = calloc(na, sizeof(int));

    if(a == NULL)
        puts("failed to memory allocation");
    else {
        printf("Enter the %d numbers.\n", na);
        for(i = 0; i < na; i++) {
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }
        printf("Below is the value of each components.\n");
        for(i =0; i < na; i++)
            printf("a[%d] = %d\n", i, a[i]);
        free(a);
    }

    return 0;
}