#include <stdio.h>

void spira(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n+i; j++) {
            if (j < n-i-1)  printf(" ");
            else            printf("*");
        }
        putchar('\n');
    }
}

void nrspira(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2*n-i; j++) {
            if (j >= i) printf("%d", i % 10);
            else        printf(" ");
        }
        putchar('\n');
    }
}

int main(void) {
    spira(0);
    putchar('\n');
    nrspira(4);

    return 0;

}