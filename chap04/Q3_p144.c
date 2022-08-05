#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;
    int num;
    int *que;
} ArrayIntQueue;

int initialize(ArrayIntQueue *q, int max) {
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(ArrayIntQueue *q, int x) {
    if (q->max <= q->num) {
        return -1;
    }
    q->que[q->num++] = x;
    return 0;
}

int Deque(ArrayIntQueue *q, int *x) {
    if (q->num == 0) {
        return -1;
    }
    *x = q->que[0];
    q->num--;
    for(int i = 0; i < q->num; i++) {
        q->que[i] = q->que[i + 1];
    }
    return 0;
}

int Peek(ArrayIntQueue *q, int *x) {
    if (q->num == 0) {
        return -1;
    }
    *x = q->que[0];
    return 0;
}

void Clear(ArrayIntQueue *q) {
    q->num = 0;
}

int Capacity(const ArrayIntQueue *q) {
    return q->max;
}

int Size(const ArrayIntQueue *q) {
    return q->num;
}

int IsEmpty(const ArrayIntQueue *q) {
    return q->num == 0;
}

int IsFull(const ArrayIntQueue *q) {
    return q->num == q->max;
}

int Search(const ArrayIntQueue *q, int x) {
    for(int i = 0; i < q->num; i++) {
        if (q->que[i] == x) {
            return i;
        }
    }
    return -1;
}

void Print(const ArrayIntQueue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("q->que[%d]: %d ", i, q->que[i]);
    }
    puts("");
}

void Terminate(ArrayIntQueue *q) {
    if (q->que != NULL)
        free(q->que);
    q->num = q->max = 0;
}

int main(void) {
    ArrayIntQueue q;
    int x;
    initialize(&q, 3);
    printf("Capacity: %d, Size: %d, IsEmpty: %d, IsFull: %d\n", Capacity(&q), Size(&q), IsEmpty(&q), IsFull(&q));
    x = 1;
    if (Enque(&q, x) == -1) {
        printf("Enque failed\n");
    }
    x = 2;
    if (Enque(&q, x) == -1) {
        printf("Enque failed\n");
    }
    Print(&q);
    Peek(&q, &x);
    printf("Peeked value: %d\n", x);
    printf("Capacity: %d, Size: %d, IsEmpty: %d, IsFull: %d\n", Capacity(&q), Size(&q), IsEmpty(&q), IsFull(&q));
    x = 3;
    if (Enque(&q, x) == -1) {
        printf("Enque failed\n");
    }
    Print(&q);
    printf("Capacity: %d, Size: %d, IsEmpty: %d, IsFull: %d\n", Capacity(&q), Size(&q), IsEmpty(&q), IsFull(&q));
    if (Deque(&q, &x) == -1) {
        printf("Deque failed\n");
    }
    Print(&q);
    x = Search(&q, 3);
    printf("Searched value is in %d.\n", x);
    Clear(&q);
    Print(&q);
    printf("Capacity: %d, Size: %d, IsEmpty: %d, IsFull: %d\n", Capacity(&q), Size(&q), IsEmpty(&q), IsFull(&q));
    Terminate(&q); 
    return 0;
}
