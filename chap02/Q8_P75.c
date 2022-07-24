#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printarr(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}

void ary_copy(int a[], const int b[], int n) {
    for(int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void ary_rcopy(int a[], const int b[], int n) {
    for(int i = 0; i < n; i++) {
        a[n - i - 1] = b[i];
    }
}

bool repeat_check(int a[], int x, int n) {
    bool b = false;
    for(int i = 0; i < n; i++) {
        if (x == a[i]) {
            b = true;
        }
    }
    return b;
}

void shuffle(int a[], int n){
    int *b;
    int r[n];
    ary_copy(b, a, n);
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        do {
            r[i] = rand() % n;
        } while(repeat_check(r, r[i], i));
        a[i] = b[r[i]];
    }
}

int main(void) {
    int number;
    int *b;
    int *a;
    printf("number of array: ");
    scanf("%d", &number);
    b = calloc(number, sizeof(int));
    a = calloc(number, sizeof(int));
    for(int i = 0; i < number; i++) {
        printf("b[%d] is: ", i);
        scanf("%d", &b[i]);
    }
    ary_rcopy(a, b, number);
    shuffle(a, number);
    printarr(a, number);
}