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

// Recursive helper for normal LL
struct Node* LLRecHelper(int size) {
    if (size <= 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* newNode = createNode(val);
    newNode->next = LLRecHelper(size - 1);
    return newNode;
}

// Full normal LL creation
struct Node* fullLLCreation(int size) {
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    head->next = LLRecHelper(size - 1);
    return head;
}

// Print normal LL
void printLL(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Recursive helper for circular LL
struct Node* CLLRecHelper(struct Node* head, struct Node* prev, int size) {
    if (size <= 0) {
        prev->next = head;  // close the loop
        return prev;
    }
    int val;
    scanf("%d", &val);
    struct Node* newNode = createNode(val);
    prev->next = newNode;
    return CLLRecHelper(head, newNode, size - 1);  // ✅ move prev forward
}

// Full circular LL creation
struct Node* fullCLLCreation(int size) {
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    CLLRecHelper(head, head, size - 1);
    return head;
}

// Print circular LL (print each node once)
void printCLL(struct Node* head) {
    if (head == NULL) return;
    struct Node* curr = head;
    do {
        printf("%d->", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

int main() {
    int size1;
    printf("Enter the size for linked list: ");
    scanf("%d", &size1);
    printf("Enter the elements for linked list:\n");
    struct Node* head = fullLLCreation(size1);
    printf("Singly Linked List:\n");
    printLL(head);

    int size2;
    printf("Enter the size for circular linked list: ");
    scanf("%d", &size2);
    printf("Enter the elements for circular linked list:\n");
    struct Node* chead = fullCLLCreation(size2);
    printf("Circular Linked List:\n");
    printCLL(chead);

    return 0;
}
