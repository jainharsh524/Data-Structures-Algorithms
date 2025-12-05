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

struct Node* CLLRecHelper(struct Node* head, struct Node* prev, int val, int size){
    if(size<=0){
        prev->next = head;
        return prev;
    }
    struct Node* curr = createNode(val++);
    prev->next = curr;
    return CLLRecHelper(head, curr, val, size-1);
}
struct Node* fullCLLCreation(int size){
    int val = 1;
    struct Node* head = createNode(val++);
    CLLRecHelper(head, head, val, size-1);
    return head;
}
void printCLL(struct Node* head) {
    if (head == NULL) return;
    struct Node* curr = head;
    do {
        printf("%d->", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("HEAD\n");
}

int kill(struct Node* head, int k, int size){
    int i =1;
    while(i<size){
        struct Node* curr = head;
        for (int count = 2; count < k; count++) {
            curr = curr->next;
        }
        struct Node* temp = curr->next->next;
        curr->next = temp;
        head = temp;
        i++;
    }
    return head->data;
}



int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    struct Node* head = fullCLLCreation(n);
    printCLL(head);
    int result = kill(head, k, n);
    printf("%d\n", result);
    return 0;
}