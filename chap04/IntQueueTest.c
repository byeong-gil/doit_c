#include <stdio.h>
#include "IntQueue.h"

int main(void) 
{
    IntQueue que;

    if(Initialize(&que, 64) == -1) {
        puts("Faile to create queue.");
        return 1;
    }
    while(1) {
        int m, x, v;
        printf("number of current data: %d / %d\n", Size(&que), Capacity(&que));
        printf("(1)Enqueue  (2)Dequeue  (3)Peek   (4)Clear  (5)Capacity (6)Size\
              \n(7)IsEmpty (8)IsFull (9)Search (10)Search2  (11)Print   (0)Terminate: ");
        scanf("%d", &m);
        if(m == 0) break;
        switch(m) {
            case 1: //Enqueue
                printf("Data: ");
                scanf("%d", &x);
                if(Enqueue(&que, x) == -1)
                    puts("\aERROR: Failed to Enqueue");
                break;

            case 2: //Dequeue
                if(Dequeue(&que, &x) == -1)
                    puts("\aERROR: Failed to Dequeue");
                else   
                    printf("The poped data is %d.\n", x);
                break;

            case 3: //Peek
                if(Peek(&que, &x) == -1)
                    puts("\aERROR: Failed to Peek");
                else   
                    printf("The peek data is %d.\n", x);
                break;

            case 4: //Clear
                Clear(&que);
                break;

            case 5: //Capacity
                printf("Capacity of the queue is %d.\n", Capacity(&que));
                break;

            case 6: //Size
                printf("Size of the queue is %d.\n", Size(&que));
                break;

            case 7: //IsEmpty
                if (IsEmpty(&que)) {
                    puts("This queue is empty");
                } else {
                    puts("This queue isn't empty");
                }
                break;

            case 8: //IsFull
                if (IsFull(&que)) {
                    puts("This queue is full");
                } else {
                    puts("This queue isn't full");
                }
                break;

            case 9: //Search
                printf("Search value: ");
                scanf("%d", &x);
                v = Search(&que, x);
                if (v == -1) {
                    puts("Failed to search");
                } else {
                    printf("Search value %d is in que[%d].\n", x, v);
                }
                break;

            case 10: //Search
                printf("Search value: ");
                scanf("%d", &x);
                v = Search2(&que, x);
                if (v == -1) {
                    puts("Failed to search");
                } else {
                    printf("Search value %d's index is %d.\n", x, v);
                }
                break;

            case 11: //Print
                Print(&que);
                break;

            default:
                puts("Please enter the number between 0 and 10");
        }
    }
    Terminate(&que);
    return 0;
}