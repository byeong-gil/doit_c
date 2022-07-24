#include <stdio.h>

typedef struct {
    int y;
    int m;
    int d;
} Date;

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

Date DateOf(int y, int m, int d) {
    return (Date) {y, m, d};
}

Date After(Date x, int n) {
    for (int i = 0; i < n; i++) {
        //printf("%dth iteration: %d.%d.%d\n", i, x.y, x.m, x.d);
        if(x.d == mdays[isleap(x.y)][x.m-1]){
            if(x.m == 12) {
                x.y += 1;
                x.m = 1;
            } else {
                x.m += 1;
            }
            x.d = 1;
        } else {
            x.d += 1;
        }
    }
    return x;
}

Date Before(Date x, int n) {
    for (int i = 0; i < n; i++) {
        if(x.d == 1){
            if(x.m == 1) {
                x.y -= 1;
                x.m = 12;
                x.d = 31;
            } else {
                x.m -= 1;
                x.d = mdays[isleap(x.y)][x.m-1];
            }
        } else {
            x.d -= 1;
        }
    }
    return x;
}

void print_date(Date x) {
    printf("%d.%d.%d\n", x.y, x.m, x.d);
}

int main(void) {
    Date x = DateOf(2022, 07, 24);
    Date y = DateOf(2022, 12, 31);
    Date z = DateOf(2022, 01, 01);

    printf("Today is ");
    print_date(x);

    printf("10 days after from today is ");
    print_date(After(x, 10));

    printf("10 days before from today is ");
    print_date(Before(x, 10));

    printf("100 days after from today is ");
    print_date(After(x, 100));

    printf("100 days before from today is ");
    print_date(Before(x, 100));

    printf("One day after from 2022.12.31 is ");
    print_date(After(y, 1));

    printf("One day before from 2022.01.01 is ");
    print_date(Before(z, 1));

    return 0;
}