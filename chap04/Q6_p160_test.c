#include <stdio.h>
#include "Q6_p160.h"

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
        printf("(1)Enqueue_front (2)Enqueue_back  (3)Dequeue_front  (4)Dequeue_back   (5)Peek_front (6)Peek_back\
        \n(7)Clear (8)Capacity (9)Size (10)IsEmpty (11)IsFull (12)Search (13)Search2  (14)Print   (0)Terminate: ");
        scanf("%d", &m);
        if(m == 0) break;
        switch(m) {
            case 1: //Enqueue
                printf("Data to enqueue front: ");
                scanf("%d", &x);
                if(Enqueue_front(&que, x) == -1)
                    puts("\aERROR: Failed to Enqueue");
                break;

            case 2: //Enqueue_back
                printf("Data to enqueue back: ");
                scanf("%d", &x);
                if(Enqueue_back(&que, x) == -1)
                    puts("\aERROR: Failed to Enqueue");
                break;

            case 3: //Dequeue
                if(Dequeue_front(&que, &x) == -1)
                    puts("\aERROR: Failed to Dequeue");
                else   
                    printf("The poped data from the front is %d.\n", x);
                break;

            case 4: //Dequeue
                if(Dequeue_back(&que, &x) == -1)
                    puts("\aERROR: Failed to Dequeue");
                else   
                    printf("The poped data from the back is %d.\n", x);
                break;

            case 5: //Peek
                if(Peek_front(&que, &x) == -1)
                    puts("\aERROR: Failed to Peek");
                else   
                    printf("The peek data from the front is %d.\n", x);
                break;

            case 6: //Peek
                if(Peek_back(&que, &x) == -1)
                    puts("\aERROR: Failed to Peek");
                else   
                    printf("The peek data from the back is %d.\n", x);
                break;

            case 7: //Clear
                Clear(&que);
                break;

            case 8: //Capacity
                printf("Capacity of the queue is %d.\n", Capacity(&que));
                break;

            case 9: //Size
                printf("Size of the queue is %d.\n", Size(&que));
                break;

            case 10: //IsEmpty
                if (IsEmpty(&que)) {
                    puts("This queue is empty");
                } else {
                    puts("This queue isn't empty");
                }
                break;

            case 11: //IsFull
                if (IsFull(&que)) {
                    puts("This queue is full");
                } else {
                    puts("This queue isn't full");
                }
                break;

            case 12: //Search
                printf("Search value: ");
                scanf("%d", &x);
                v = Search(&que, x);
                if (v == -1) {
                    puts("Failed to search");
                } else {
                    printf("Search value %d is in que[%d].\n", x, v);
                }
                break;

            case 13: //Search
                printf("Search value: ");
                scanf("%d", &x);
                v = Search2(&que, x);
                if (v == -1) {
                    puts("Failed to search");
                } else {
                    printf("Search value %d's index is %d.\n", x, v);
                }
                break;

            case 14: //Print
                Print(&que);
                break;

            default:
                puts("Please enter the number between 0 and 10");
        }
    }
    Terminate(&que);
    return 0;
}