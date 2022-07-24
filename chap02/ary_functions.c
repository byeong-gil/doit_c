#include <stdio.h>
#include <stdlib.h>

/*---Get a max number in n integer array a---*/
int maxof(const int a[], int n)
{
    int i;
    int max = a[0];
    for(i = 1; i < n; i++)
        if(a[i] > max) max = a[i];
    return max;
}

int minof(const int a[], int n)
{
    int i;
    int min = a[0];
    for(i = 1; i < n; i++)
        if(a[i] < min) min = a[i];
    return min;
}

int sumof(const int a[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

double aveof(const int a[], int n)
{
    return sumof(a, n) / (double)n;
}

int main(void)
{
    int i;
    int *height;
    int number;
    printf("number of people : ");
    scanf("%d", &number);
    height = calloc(number, sizeof(int));
    printf("Enter the %d person's height.\n", number);
    for(i = 0; i< number; i++) {
        printf("height[%d] : ", i);
        scanf("%d", &height[i]);
    }
    printf("Maximum height is %d.\n", maxof(height, number));
    printf("Minimum height is %d.\n", minof(height, number));
    printf("Sum of the height is %d.\n", sumof(height, number));
    printf("Average of the height is %f.\n", aveof(height, number));
    free(height);

    return 0;
}