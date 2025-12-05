#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, int val) {
    if (q->size == MAX) {
        printf("Queue overflow\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % MAX;
    q->data[q->rear] = val;
    q->size++;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue underflow\n");
        exit(EXIT_FAILURE);
    }
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

int peek(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->data[q->front];
}

typedef struct {
    Queue q;
} Stack;

void initStack(Stack* st) {
    initQueue(&st->q);
}

bool isEmpty(Stack* st) {
    return isQueueEmpty(&st->q);
}

void push(Stack* st, int x) {
    enqueue(&st->q, x);
    int rotate = st->q.size - 1;
    while (rotate--) {
        enqueue(&st->q, dequeue(&st->q));  // Move older elements to back
    }
}

int pop(Stack* st) {
    return dequeue(&st->q);
}

int top(Stack* st) {
    return peek(&st->q);
}

int main() {
    Stack st;
    initStack(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("Top: %d\n", top(&st));  // 30
    printf("Pop: %d\n", pop(&st));  // 30
    printf("Top: %d\n", top(&st));  // 20
    printf("Pop: %d\n", pop(&st));  // 20
    printf("Is Empty: %d\n", isEmpty(&st)); // 0 (false)

    return 0;
}
