// int type stack IntQueue(Source)
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

// Initialize the stack
int Initialize(IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0; //failed to construct a stack
        return -1;
    }
    q->max = max;
    return 0;
}

int Enqueue(IntQueue *q, int x)
{
    if(q->num >= q->max) //If the stack is full
        return -1;
    else {
        q->num++;
        q->que[q->rear++] = x;
        if(q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

int Dequeue(IntQueue *q, int *x)
{
    if(q->num <= 0) //If the stack is empty
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if(q->front == q->max)
            q->front = 0;
        return 0;
    }
}

int Peek(const IntQueue *q, int *x)
{
    if(q->num <= 0) //If the stack is empty
        return -1;
    *x = q->que[q->front];
    return 0;
}

void Clear(IntQueue *q) 
{
    q->num = q->front = q->rear = 0;
}

int Capacity(const IntQueue *q) 
{   
    return q->max;
}

int Size(const IntQueue *q)
{
    return q->num;
}

int IsEmpty(const IntQueue *q)
{
    return q->num <= 0;
}

int IsFull(const IntQueue *q)
{
    return q->num >= q->max;
}

int Search(const IntQueue *q, int x)
{
    int i, idx;
    for(i = 0; i < q->num; i++) {
        if(q->que[idx = (i + q->front) % q->max] == x){
            return idx; // Searching success
        }
            
    }
    return -1;  // Failed to search
}

int Search2(const IntQueue *q, int x)
{
    int i;
    for (i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x) {
            return i;
        }
    }
    return -1;
}

void Print(const IntQueue *q)
{
    int i;
    for(i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

void Terminate(IntQueue *q)
{
    if(q->que != NULL)
        free(q->que);   //free allocated array
    q->max = q->num = q->front = q->rear = 0;
}