#include <stdio.h>

void trianlgeLB (int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            printf("*");
        putchar('\n');
    }
}

void trianlgeLU (int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++)
            printf("*");
        putchar('\n');
    }
}

void trianlgeRU (int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if (j < i)  printf(" ");
            else        printf("*");
        putchar('\n');
    }
}

void trianlgeRB (int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if (j <= i)  printf("*");
            else        printf(" ");
        putchar('\n');
    }
}

int main(void) {
    trianlgeLB(4);
    putchar('\n');
    trianlgeLU(4);
    putchar('\n');
    trianlgeRU(4);
    putchar('\n');
    trianlgeRB(4);
}