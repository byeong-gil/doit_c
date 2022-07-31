// int type stack IntStack(header)
#ifndef ___IntStack
#define ___IntStack

// struct to implement stack
typedef struct {
    int max;    // Stack size
    int top;    // Stack pointer
    int *bot;   // A pointer about the first element of stack
} IntStack;

// Initialize stack
int Initialize(IntStack *a, IntStack *b, int max);

// Push to the stack
int Push(IntStack *a, IntStack *b, int x, int arg);

// Pop from the stack
int Pop(IntStack *a, IntStack *b, int *x, int arg);

// Peek data from the stack
int Peek(const IntStack *a, const IntStack *b, int *x, int arg);

// Clear the stack
void Clear(IntStack *a, IntStack *b, int arg);

// Capacity of the stack
int Capacity(const IntStack *a, const IntStack *b, int arg);

// A number of data in the stack
int Size(const IntStack *a, const IntStack *b, int arg);

// Is the stack empty?
int IsEmpty(const IntStack *a, const IntStack *b, int arg);

// Is the stack full?
int IsFull(const IntStack *a, const IntStack *b);

// Search through the stack
int Search(const IntStack *a, const IntStack *b, int x, int arg);

// Print all datas
void Print(const IntStack *a, const IntStack *b, int arg);

// Terminate the stack
void Terminate(IntStack *a, IntStack *b);
#endif