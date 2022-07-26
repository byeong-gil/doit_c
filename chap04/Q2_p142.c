#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1){
        puts("Failed to construct a stack");
        return -1;
    }    

    while(1) {
        int menu, x;
        printf("number of current data: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Push  (2)Pop     (3)Peek   (4)Clear  (5)Capacity (6)Size \
              \n(6)Size  (7)IsEmpty (8)IsFull (9)Search (10)Print   (0)Terminate: ");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch(menu) {
            case 1: //Push
                printf("Data: ");
                scanf("%d", &x);
                if(Push(&s, x) == -1)
                    puts("\aERROR: Failed to Push");
                break;

            case 2: //Pop
                if(Pop(&s, &x) == -1)
                    puts("\aERROR: Failed to Pop");
                else   
                    printf("The poped data is %d.\n", x);
                break;

            case 3: //Peek
                if(Peek(&s, &x) == -1)
                    puts("\aERROR: Failed to Peek");
                else   
                    printf("The peek data is %d.\n", x);
                break;

            case 4: //Clear
                Clear(&s);
                break;

            case 5: //Capacity
                printf("Capacity of the stack is %d.\n", Capacity(&s));
                break;

            case 6: //Size
                printf("Size of the stack is %d.\n", Size(&s));
                break;

            case 7: //IsEmpty
                if (IsEmpty(&s)) {
                    puts("This stack is empty");
                } else {
                    puts("This stack isn't empty");
                }
                break;

            case 8: //IsFull
                if (IsFull(&s)) {
                    puts("This stack is full");
                } else {
                    puts("This stack isn't full");
                }
                break;

            case 9: //Search
                printf("Search value: ");
                scanf("%d", &x);
                int v = Search(&s, x);
                if (v == -1) {
                    puts("Failed to search");
                } else {
                    printf("Search value %d is in s[%d].\n", x, v);
                }
                break;

            case 10: //Print
                Print(&s);
                break;

            default:
                puts("Please enter the number between 0 and 10");
        }
    }
    Terminate(&s);
    return 0;
}