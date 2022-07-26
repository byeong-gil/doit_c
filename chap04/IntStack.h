// int type stack IntStack(header)
#ifndef ___IntStack
#define ___IntStack

// struct to implement stack
typedef struct {
    int max;    // Stack size
    int ptr;    // Stack pointer
    int *stk;   // A pointer about the first element of stack
} IntStack;

// Initialize stack
int Initialize(IntStack *s, int max);

// Push to the stack
int Push(IntStack *s, int x);

// Pop from the stack
int Pop(IntStack *s, int *x);

// Peek data from the stack
int Peek(const IntStack *s, int *x);

// Clear the stack
void Clear(IntStack *s);

// Capacity of the stack
int Capacity(const IntStack *s);

// A number of data in the stack
int Size(const IntStack *s);

// Is the stack empty?
int IsEmpty(const IntStack *s);

// Is the stack full?
int IsFull(const IntStack *s);

// Search through the stack
int Search(const IntStack *s, int x);

// Print all datas
void Print(const IntStack *s);

// Terminate the stack
void Terminate(IntStack *s);
#endif