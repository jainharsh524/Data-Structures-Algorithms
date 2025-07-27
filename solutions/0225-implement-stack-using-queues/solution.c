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
} MyStack;


MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&st->q);
    return st;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q, x);
    int rotation = obj->q.size-1;
    while(rotation){
        enqueue(&obj->q, dequeue(&obj->q));
        rotation--;
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q);
}

int myStackTop(MyStack* obj) {
    return peek(&obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
