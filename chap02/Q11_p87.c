#include <stdio.h>

//number of day of each month
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// is year a leap year?
int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

// get a number of past day at y year m month d day
int dayofyear(int y, int m, int d)
{
    while(m > 1) {
        d += mdays[isleap(y)][--m];
    }
    return d;
}

int main(void)
{
    int year, month, day;
    int retry;
    do {
        printf("year: "); scanf("%d", &year);
        printf("month: "); scanf("%d", &month);
        printf("day: "); scanf("%d", &day);
        printf("%dyear %dth day.\n", year, dayofyear(year, month, day));
        printf("Wanna retry?(1 --- yes/ 0 --- no) : ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}