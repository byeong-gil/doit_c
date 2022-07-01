#include <stdio.h>

int main(void) 
{
    int no;
    printf("Enter a two digits.\n");
    do {
        printf("number : ");
        scanf("%d", &no);
    } while(no < 10 || no > 99); // same as !(no >= 10 && no <= 99) by De morgan's law
    printf("variable no becomes %d.\n", no);

    return 0;
}