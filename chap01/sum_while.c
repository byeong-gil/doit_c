#include <stdio.h>

int main (void)
{
    int i, n;
    int sum;
    puts("get a sum of 1 to n");
    printf("n : ");
    scanf("%d", &n);
    sum = 0;
    i = 1;
    while(i <= n) { //iterate when i is less or equal than n
        printf("i's current value is %d.\n", i);
        sum += i;   //add i to sum
        i++;        //increment i by 1
    }
    printf("sum of 1 to %d is %d.\n", n, sum);

    return 0;
}