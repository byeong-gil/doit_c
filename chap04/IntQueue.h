// int type stack IntQueue(header)
#ifndef ___IntQueue
#define ___IntQueue

// struct to implement stack
typedef struct {
    int max;    // Max capcaity of queue
    int num;    // Number of current elements
    int front;  // front
    int rear;   // rear
    int *que;   // pointer that point to the first element of queue 
} IntQueue;

// Initialize stack
int Initialize(IntQueue *q, int max);

// Push to the stack
int Enqueue(IntQueue *q, int x);

// Pop from the stack
int Dequeue(IntQueue *q, int *x);

// Peek data from the stack
int Peek(const IntQueue *q, int *x);

// Clear the stack
void Clear(IntQueue *q);

// Capacity of the stack
int Capacity(const IntQueue *q);

// A number of data in the stack
int Size(const IntQueue *q);

// Is the stack empty?
int IsEmpty(const IntQueue *q);

// Is the stack full?
int IsFull(const IntQueue *q);

// Search through the stack
int Search(const IntQueue *q, int x);

int Search2(const IntQueue *q, int x);

// Print all datas
void Print(const IntQueue *q);

// Terminate the stack
void Terminate(IntQueue *q);
#endif