#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* LLRecHelper(int size) {
    if (size <= 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* newNode = createNode(val);
    newNode->next = LLRecHelper(size - 1);
    return newNode;
}

struct Node* fullLLCreation(int size) {
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    head->next = LLRecHelper(size - 1);
    return head;
}

void printLL(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

//Q. https://leetcode.com/problems/linked-list-cycle/description/
bool hasCycle(struct Node* head){
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    while(fastPtr->next!=NULL&&fastPtr->next->next!=NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if(slowPtr==fastPtr){
            return true;
        }
    }
    return false;
}

// struct Node* detectCycle(struct Node *head) {
//     struct Node* slowPtr = head;
//     struct Node* fastPtr = head;
//     int count = 0;
//     while (fastPtr != NULL && fastPtr->next != NULL) {
//         slowPtr = slowPtr->next;
//         fastPtr = fastPtr->next->next;

//         if (slowPtr == fastPtr) {
//             struct Node* temp = slowPtr->next;
//             while (temp != slowPtr) {
//                 count++;
//                 temp = temp->next;
//             }
//             if(count==0){ return NULL;}
//             else{
//                 count++;
//             }
//         }
//     }
//     int size = 0;
//     struct Node* curr = head;
//     struct Node* temp = head;
//     while(curr!=slowPtr){
//         curr = curr->next;
//     }
//     int tot_size = size+count;
//     int currNodePtr = 0;
//     while(temp!=NULL){
//         curr = temp->next;
//         while(currNodePtr<tot_size&&curr!=temp){
//             curr = curr->next;
//             currNodePtr++;
//         }
//         if(curr==temp){
//             return temp;
//         }
//         else{
//             temp = temp->next;
//         }
//     }
//     return NULL;
// }

//Q. https://leetcode.com/problems/linked-list-cycle-ii/description/
//Sol. https://leetcode.com/problems/linked-list-cycle-ii/solutions/7012896/easy-solution-in-c-and-a-challenge-at-last-of-the-solution/
struct Node* detectCycle(struct Node *head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct Node* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL;
}

int main() {
    int size1;
    printf("Enter the size for linked list: ");
    scanf("%d", &size1);
    printf("Enter the elements for linked list:\n");
    struct Node* head = fullLLCreation(size1);
    printf("Singly Linked List:\n");
    printLL(head);
    return 0;
}
