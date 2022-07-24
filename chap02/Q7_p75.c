#include <stdio.h>

int card_conv(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;
    int y = x;
    while(y) {
        y /= n;
        digits++;
    }

    for(int i = digits-1; i >= 0; i--) {
        printf("%d|    %d ... %d\n", n, x, (x % n));
        printf(" +-------\n");
        d[i] = dchar[x % n];
        x /= n;
    }
    printf("      0\n");
    return digits;
}

int main(void)
{
    int i;
    unsigned no;    //integer that will be transformed
    int cd;         //notation
    int dno;        //digit after transform
    char cno[512];  //array to store each digit of transformed number
    int retry;
    puts("converts a decimal to any notation");
    do {
        printf("non negative integer : ");
        scanf("%u", &no);
        do {
            printf("What notation this number is converted?(2-36) : ");
            scanf("%d", &cd);
        } while(cd < 2 || cd > 36);
        dno = card_conv(no, cd, cno);
        printf("this number is ");
        for(i = 0; i < dno; i++)
            printf("%c", cno[i]);
        printf(" as notation of %d.\n", cd);
        printf("One more?(1 --- yes/0 --- no) : ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}