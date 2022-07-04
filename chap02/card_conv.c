#include <stdio.h>

int card_convr(unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    if(x == 0)
        d[digits++] = dchar[0];
    else
        while(x) {
            d[digits++] = dchar[x % n];
            x /= n;
        }
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
        dno = card_convr(no, cd, cno);  //convert no to cd notation
        printf("this number is ");
        for(i = dno - 1; i >= 0; i--)   //flip the return value
            printf("%c", cno[i]);
        printf(" as notation of %d.\n", cd);
        printf("One more?(1 --- yes/0 --- no) : ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}