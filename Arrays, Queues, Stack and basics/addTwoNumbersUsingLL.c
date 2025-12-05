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
//Q. https://leetcode.com/problems/add-two-numbers/description/
//SOl.https://leetcode.com/problems/add-two-numbers/solutions/7017076/beats-100-easy-solution-in-c-using-linke-516b/
struct Node* sum(struct Node* head1, struct Node* head2, int size1, int size2){
    struct Node* curr1 = head1;
    struct Node* curr2 = head2;
    int sum = 0;
    int carry = 0;
    while(curr1!=NULL&&curr2!=NULL){
        sum = curr1->data+curr2->data+carry;
        if(sum >= 10){
            sum = sum-10;
            carry = 1;
            if(size1<size2){
                curr2->data = sum;
            }
            else{
                curr1->data = sum;
            }
        }
        else{
            carry = 0;
            if(size1<size2){
                curr2->data = sum;
            }
            else{
                curr1->data = sum;
            }
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(size1<size2){
        while (curr2!=NULL)
        {
            sum = curr2->data+carry;
            if(sum >= 10){
                sum = sum-10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            curr2->data = sum;
            curr2 = curr2->next;
        }
    }
    else{
        while (curr1!=NULL)
        {
            sum = curr1->data+carry;
            if(sum >= 10){
                sum = sum-10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            curr1->data = sum;
            curr1 = curr1->next;
        }
    }
    struct Node* temp;
    struct Node* extra;
    if(carry==1){
        if(size1<size2){
            temp = head1;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            extra = createNode(carry);
            temp->next = extra;
        }
        else{
            temp = head1;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            extra = createNode(carry);
            temp->next = extra;
        }
    }
    if(size1<size2) return head2;
    else return head1;
}

int main(){
    int size1, size2;
    scanf("%d", &size1);
    scanf("%d", &size2);
    struct Node* head1 = fullLLCreation(size1);
    struct Node* head2 = fullLLCreation(size2);
    struct Node* res = sum(head1, head2, size1, size2);
    printLL(res);
    return 0;
}