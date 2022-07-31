// int type stack IntStack(Source)
#include <stdio.h>
#include <stdlib.h>
#include "Q2_p142.h"

// Initialize the stack
int Initialize(IntStack *a, IntStack *b, int max)
{
    a->top = 0;
    b->top = 0;
    if ((a->bot = calloc(max, sizeof(int))) == NULL) {
        a->max = 0; //failed to construct a stack
        b->max = 0;
        return -1;
    }
    b->bot = a->bot;
    a->max = max;
    b->max = max;
    return 0;
}

int Push(IntStack *a, IntStack *b, int x, int arg)
{
    if(a->top + b->top > 64) //If the stack is full
        return -1;
    if(arg == 0) {
        a->bot[a->top++] = x;
    } else {
        b->bot[b->max - 1 - (b->top++)] = x;
    }
    return 0;
}

int Pop(IntStack *a, IntStack *b, int *x, int arg)
{
    if(arg == 0) {
        if(a->top == 0) // if a is emptry
            return -1;
        *x = a->bot[--a->top];
    } else {
        if(b->top == b->max) // if b is empty
            return -1;
        *x = b->bot[b->max - 1 - (--b->top)];
    }
    return 0;
}

int Peek(const IntStack *a, const IntStack *b, int *x, int arg)
{
    if(arg == 0) {
        if(a->top == 0) // if a is emptry
            return -1;
        *x = a->bot[a->top - 1];
    } else {
        if(b->top == 0) {// if b is empty`
            return -1;
        }
        *x = b->bot[b->max - 1 - (b->top - 1)];
    }
    return 0;
}

void Clear(IntStack *a, IntStack *b, int arg)
{    
    if(arg == 0) {
        a->top = 0;
    } else {
        b->top = 0;
    }
}

int Capacity(const IntStack *a, const IntStack *b, int arg)
{
    if(arg == 0) {
        return a->max;
    } else {
        return b->max;
    }
}

int Size(const IntStack *a, const IntStack *b, int arg)
{
    if(arg == 0) {
        return a->top;
    } else {
        return b->top;
    }
}

int IsEmpty(const IntStack *a, const IntStack *b, int arg)
{
    if(arg == 0) {
        return a->top <= 0;
    } else {
        return b->top <= 0;
    }
}

int IsFull(const IntStack *a, const IntStack *b)
{
    return (a->top + b->top) > a->max;
}

int Search(const IntStack *a, const IntStack *b, int x, int arg)
{
    int i;
    if(arg == 0) {
        for(i = a->top -1; i >= 0; i--) // Linear search starts from top to bottom
        if(a->bot[i] == x)
            return i;
    } else {
        for(i = b->top -1; i >= 0; i--) // Linear search starts from top to bottom
        if(b->bot[b->max - 1 - i] == x)
            return i;
    }
    return -1;  //Failed to search
}

void Print(const IntStack *a, const IntStack *b, int arg)
{
    int i;
    if(arg == 0) {
        for(i = 0; i < a->top; i++)
            printf("%d", a->bot[i]);
    } else {
        for(i = 0; i < b->top; i++)
            printf("%d", b->bot[b->max - 1 - i]);
    }
    putchar('\n');
}

void Terminate(IntStack *a, IntStack *b)
{
    if(a->bot != NULL)
        free(a->bot);
    a->max = a->top = 0;
    b->max = b->top = 0;
}