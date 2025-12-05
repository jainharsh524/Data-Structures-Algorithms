#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


struct Node {
    int min;
    int data;
    struct Node* next;
};

struct stack{
    struct Node* top_ptr;
    int minValue;
    int size;
    int* minArray;
};
struct Node* createNode(char val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct stack* init(struct Node* top){
    struct stack* st = (struct stack*)malloc(sizeof(struct stack));
    if (st == NULL) {
        perror("Failed to allocate stack");
        exit(EXIT_FAILURE);
    }
    st->top_ptr = NULL;
}

void push(struct stack* st, int val) {
    struct Node* curr = createNode(val);
    curr->next = st->top_ptr;
    st->top_ptr = curr;
    if (val<st->minValue){
        st->minValue = val;
    }
}

char pop(struct Node** top_ptr) {
    if (*top_ptr == NULL) {
        exit(EXIT_FAILURE);
    }
    struct Node* temp = *top_ptr;
    char popped_value = temp->data;
    *top_ptr = (*top_ptr)->next;
    free(temp);
    return popped_value;
}

char peek(struct Node* top) {
    if (top == NULL) {
        return '\0';
    }
    return top->data;
}

void printStack(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack: Empty\n");
        return;
    }
    struct Node* curr = top;
    printf("Stack: TOP -> ");
    while (curr != NULL) {
        printf("%c -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}
