#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min_array(const int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }
    return min;
}

bool do_recursive(const int a[], int n, int min) {
    bool b = false;
    for (int i = 0; i < n; i++) {
        if (a[i] % min != 0) {
            b = true;
        }
    }
    return a;
}

void subtract_all(int a[], int n, int min) {
    for (int i = 0; i < n; i++) {
        if (a[i] != min)
            a[i] -= min;
    }
}

int gcd_array(int a[], int n)
{
    int min = min_array(a, n);
    if (!do_recursive(a, n, min)) {
        printf("hihihih");
        return min; 
    } else {
        subtract_all(a, n, min);
        gcd_array(a, n);
    }
}

int main(void)
{
    int* a; int x;
    if ((a = calloc(5, sizeof(int))) == NULL)
        printf("Failed to allocate memory.");
    else {
        puts("Get a gcd of 5 intagers.");
        printf("Enter an 1st integer: ");
        scanf("%d", &a[0]);
        printf("Enter an 2nd integer: ");
        scanf("%d", &a[1]);
        printf("Enter an 3rd integer: ");
        scanf("%d", &a[2]);
        printf("Enter an 4th integer: ");
        scanf("%d", &a[3]);
        printf("Enter an 5th integer: ");
        scanf("%d", &a[4]);
        printf("gcd is %d.\n", gcd_array(a, 5));
    }
    
    return 0;
}