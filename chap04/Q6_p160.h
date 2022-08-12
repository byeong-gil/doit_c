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

// Enqueue to the front of the queue
int Enqueue_front(IntQueue *q, int x);

// Enqueue to the back of the queue
int Enqueue_back(IntQueue *q, int x);

// Dequeue from the front of the stack
int Dequeue_front(IntQueue *q, int *x);

// Dequeue from the back of the stack
int Dequeue_back(IntQueue *q, int *x);

// Peek data from the front of the stack
int Peek_front(const IntQueue *q, int *x);

// Peek data from the back of the stack
int Peek_back(const IntQueue *q, int *x);

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