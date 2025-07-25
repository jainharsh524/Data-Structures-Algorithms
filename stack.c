#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;  // ✅ Important!
    return newNode;
}
struct Node* initiate(int val){
    struct Node* top = createNode(val);
    return top;
}

struct Node* push(struct Node* top, int val){
    struct Node* curr = createNode(val);
    curr->next = top;
    top = curr;
    return top;
}
struct Node* pop(struct Node* top){
    struct Node* temp = top->next;
    int popped = top->data;
    top=temp;
    printf("Popped Value: %d\n", popped);
    return top;
}
void printStack(struct Node* top) {
    struct Node* curr = top;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(){
    printf("Initiate the stack by giving the first value: ");
    int val;
    scanf("%d", &val);
    struct Node* top = initiate(val);
    top = push(top, 6);
    top = push(top, 7);
    top = push(top, 8);
    top = push(top, 9);
    top = push(top, 10);
    printStack(top);
    top = pop(top);
    printf("Stack after popping: ");
    printStack(top);
    return 0;
}