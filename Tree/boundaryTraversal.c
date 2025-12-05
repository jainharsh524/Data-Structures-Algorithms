#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int* rev(int a[], int size){
    int i = 0;
    int j = size-1;
    while(i<j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;j--;
    }
    return a;
}

// Tree Node
struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
    int height;
};

// Queue Node
struct queueNode {
    struct treeNode* n;
    struct queueNode* next;
};

// Queue
struct queue {
    struct queueNode* rear;
    struct queueNode* front;
};

// Create Tree Node
struct treeNode* createNode(int val) {
    struct treeNode* curr = (struct treeNode*)malloc(sizeof(struct treeNode));
    curr->left = NULL;
    curr->right = NULL;
    curr->val = val;
    curr->height = 0;
    return curr;
}

// Initialize Queue
struct queue* queue_init() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct queue* q, struct treeNode* root) {
    struct queueNode* temp = (struct queueNode*)malloc(sizeof(struct queueNode));
    temp->n = root;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

// Dequeue
struct treeNode* dequeue(struct queue* q) {
    if (q->front == NULL) return NULL;

    struct queueNode* temp = q->front;
    struct treeNode* curr = temp->n;
    q->front = q->front->next;

    if (q->front == NULL) q->rear = NULL;

    free(temp);
    return curr;
}

int isEmptyQueue(struct queue* q) {
    return q->front == NULL;
}

//size
int size(struct queue* q){
    int count = 0;
    struct queueNode* temp = q->front;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// Height
int height(struct treeNode* root) {
    if (root == NULL) return -1;
    return root->height;
}

bool isLeaf(struct treeNode* node){
    return node->left==NULL&&node->right==NULL;
}

// Insertion into BST
struct treeNode* insertHelper(int val, struct treeNode* root) {
    if (root == NULL) return createNode(val);

    if (val < root->val) {
        root->left = insertHelper(val, root->left);
    } else if (val > root->val) {
        root->right = insertHelper(val, root->right);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    return root;
}

// Populate Tree from array
struct treeNode* populate(int nums[], int size) {
    struct treeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertHelper(nums[i], root);
    }
    return root;
}

void leftBoundary(struct treeNode* root, int* arr, int* ptr) {
    struct treeNode* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) {
            arr[(*ptr)++] = curr->val;
        }
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Right boundary excluding leaves (store in reverse)
void rightBoundary(struct treeNode* root, int* arr, int* ptr) {
    int temp[100];
    int size = 0;
    struct treeNode* curr = root->right;
    while (curr) {
        if (!isLeaf(curr)) {
            temp[size++] = curr->val;
        }
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = size - 1; i >= 0; i--) {
        arr[(*ptr)++] = temp[i];
    }
}

// Fill leaf nodes
void leafFilling(struct treeNode* root, int* arr, int* ptr) {
    if (!root) return;
    if (isLeaf(root)) {
        arr[(*ptr)++] = root->val;
        return;
    }
    leafFilling(root->left, arr, ptr);
    leafFilling(root->right, arr, ptr);
}

int* boundaryTraversal(struct treeNode* root, int* returnSize) {
    int* result = malloc(1000 * sizeof(int));
    *returnSize = 0;
    if (!root) return result;

    if (!isLeaf(root))
        result[(*returnSize)++] = root->val;

    leftBoundary(root, result, returnSize);
    leafFilling(root, result, returnSize);
    rightBoundary(root, result, returnSize);

    return result;
}

// Display Tree (Preorder with details)
void display(struct treeNode* node, const char* detail) {
    if (node == NULL) return;

    printf("%s%d\n", detail, node->val);
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "Left child of %d: ", node->val);
    display(node->left, buffer);
    snprintf(buffer, sizeof(buffer), "Right child of %d: ", node->val);
    display(node->right, buffer);
}

void showTree(struct treeNode* root) {
    display(root, "Root Node: ");
}

// Main function
int main() {
    int arr[] = {10, 5, 15, 2, 7, 12, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct treeNode* root = populate(arr, size);

    showTree(root);

    return 0;
}
