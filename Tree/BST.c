#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Node structure
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    int height;
};

// Queue node for level order traversal
struct queueNode {
    struct Node* node;
    struct queueNode* next;
};

// Queue structure
struct queue {
    struct queueNode* rear;
    struct queueNode* front;
};

// Create queue
struct queue* createQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

// Check if queue is empty
int isEmptyQueue(struct queue* q) {
    return q->front == NULL;
}

// Enqueue a node
void enqueue(struct queue* q, struct Node* n) {
    struct queueNode* curr = (struct queueNode*)malloc(sizeof(struct queueNode));
    curr->node = n;
    curr->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = curr;
    } else {
        q->rear->next = curr;
        q->rear = curr;
    }
}

// Dequeue a node (✅ FIXED)
struct Node* dequeue(struct queue* q) {
    if (q->front == NULL) return NULL;
    struct queueNode* temp = q->front;
    struct Node* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

// Create new tree node
struct Node* createNode(int val) {
    struct Node* curr = (struct Node*)malloc(sizeof(struct Node));
    curr->val = val;
    curr->height = 0;
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

// Get height
int height(struct Node* root) {
    if (root == NULL) return -1;
    return root->height;
}

// Insert with height update
struct Node* insertHelper(int value, struct Node* root) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->val) {
        root->left = insertHelper(value, root->left);
    } else if (value > root->val) {
        root->right = insertHelper(value, root->right);
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}

// Populate BST from array
struct Node* populate(int nums[], int size) {
    struct Node* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insertHelper(nums[i], root);
    }
    return root;
}

// Recursive helper for display
void displayHelper(struct Node* node, char* details) {
    if (node == NULL) return;

    printf("%s%d\n", details, node->val);

    char leftLabel[100];
    sprintf(leftLabel, "Left child of %d: ", node->val);
    displayHelper(node->left, leftLabel);

    char rightLabel[100];
    sprintf(rightLabel, "Right child of %d: ", node->val);
    displayHelper(node->right, rightLabel);
}

// Display tree
void display(struct Node* root) {
    displayHelper(root, "Root Node: ");
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// Level-order traversal using queue
void levelorder(struct Node* root) {
    if (root == NULL) return;

    struct queue* q = createQueue();
    enqueue(q, root);

    while (!isEmptyQueue(q)) {
        struct Node* current = dequeue(q);
        printf("%d ", current->val);

        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    printf("\n");
}

int diameter(struct Node* root, int *maxi){
    if (root == NULL) return 0;

    int lheight = diameter(root->left, maxi);
    int rheight = diameter(root->right, maxi);

    *maxi = max(*maxi, lheight + rheight);  // update diameter
    return max(lheight, rheight) + 1;       // return height
}

int maxPathSum(struct Node* root, int *maxi){
    if (root == NULL) return 0;

    int left = max(0,maxPathSum(root->left, maxi));
    int right = max(0,maxPathSum(root->right, maxi));

    *maxi = max(*maxi, left + right + root->val); // update max path sum
    return max(left, right) + root->val;
}

// Main function
int main() {
    int nums[] = {20, 9, -10, -11, -15, 15, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    struct Node* root = populate(nums, size);

    display(root);

    printf("\nPreorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Levelorder: ");
    levelorder(root);
    printf("\n");

    int maxi = 0;
    printf("Maximum Path Sum: ");
    printf("%d", maxPathSum(root, &maxi));
    printf("\n");

    return 0;
}
