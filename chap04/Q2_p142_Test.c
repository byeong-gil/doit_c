#include <stdio.h>
#include "Q2_p142.h"

int main(void)
{
    IntStack a;
    IntStack b;
    if (Initialize(&a, &b, 64) == -1){
        puts("Failed to construct a stack");
        return -1;
    }    

    int menu, x;

    while(1) {
        puts("What stack do you want to control? : ");
        printf("(0) A    (1) B\n");
        int arg;
        scanf("%d", &arg);
        if (!(arg == 0 || arg == 1))
            continue;
        if(arg == 0)
            printf("Stack A, number of current data: %d / %d\n", Size(&a, &b, 0), Capacity(&a, &b, 0));
        else
            printf("Stack B, number of current data: %d / %d\n", Size(&a, &b, 1), Capacity(&a, &b, 1));
        printf("(1)Push  (2)Pop     (3)Peek   (4)Clear  (5)Capacity \
              \n(6)Size  (7)IsEmpty (8)IsFull (9)Search (10)Print   (0)Terminate: \n");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch(menu) {
            case 1: //Push
                printf("Data: ");
                scanf("%d", &x);
                if(Push(&a, &b, x, arg) == -1)
                    puts("\aERROR: Failed to Push");
                break;

            case 2: //Pop
                if(Pop(&a, &b, &x, arg) == -1)
                    puts("\aERROR: Failed to Pop");
                else   
                    printf("The poped data is %d.\n", x);
                break;

            case 3: //Peek
                if(Peek(&a, &b, &x, arg) == -1)
                    puts("\aERROR: Failed to Peek");
                else   
                    printf("The peek data is %d.\n", x);
                break;

            case 4: //Clear
                Clear(&a, &b, arg);
                break;

            case 5: //Capacity
                printf("Capacity of the stack is %d.\n", Capacity(&a, &b, arg));
                break;

            case 6: //Size
                printf("Size of the stack is %d.\n", Size(&a, &b, arg));
                break;

            case 7: //IsEmpty
                if (IsEmpty(&a, &b, arg)) {
                    puts("This stack is empty");
                } else {
                    puts("This stack isn't empty");
                }
                break;

            case 8: //IsFull
                if (IsFull(&a, &b)) {
                    puts("This stack is full");
                } else {
                    puts("This stack isn't full");
                }
                break;

            case 9: //Search
                printf("Search value: ");
                scanf("%d", &x);
                int v = Search(&a, &b, x, arg);
                if (v == -1) {
                    puts("Failed to search");
                } else if (arg == 0) {
                    printf("Search value %d is in a[%d].\n", x, v);
                } else {
                    printf("Search value %d is in b[%d].\n", x, v);
                }
                break;

            case 10: //Print
                Print(&a, &b, arg);
                break;

            default:
                puts("Please enter the number between 0 and 10");
        }
    }
    Terminate(&a, &b);
    return 0;
}