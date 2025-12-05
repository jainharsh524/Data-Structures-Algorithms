#include <stdio.h>
#include <stdlib.h>

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
    int height;  // should be int, not pointer
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

void levelorder(struct treeNode* root, struct queue* q){
    if(root==NULL) return;
    
    enqueue(q, root);
    while(!isEmptyQueue(q)){
        struct treeNode* curr = dequeue(q);
        printf("%d ", curr->val);

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
}

void zigzag(int** res, int* returnSize, int** returnColumnSizes, struct treeNode* root, int flag, struct queue* q) {
    if (root == NULL) return;

    enqueue(q, root);

    while (!isEmptyQueue(q)) {
        int levelSize = size(q);
        res[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct treeNode* curr = dequeue(q);
            int index = (flag) ? (levelSize - i - 1) : i;

            res[*returnSize][index] = curr->val;

            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }

        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
        flag = !flag;
    }
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
