#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Step 1: Inorder traversal to store sorted values
void storeInorder(struct Node* root, int arr[], int* index) {
    if (!root) return;
    storeInorder(root->left, arr, index);
    arr[(*index)++] = root->data;
    storeInorder(root->right, arr, index);
}

// Step 2: Preorder traversal to replace values from array
void bstToMinHeap(struct Node* root, int arr[], int* index) {
    if (!root) return;
    root->data = arr[(*index)++];
    bstToMinHeap(root->left, arr, index);
    bstToMinHeap(root->right, arr, index);
}

// Utility to print level order (to verify Min Heap)
void printLevelOrder(struct Node* root) {
    if (!root) return;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
}

int main() {
    /* Example BST (Complete Tree)
            4
           / \
          2   6
         / \ / \
        1  3 5  7
    */
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    int arr[100], index = 0;
    storeInorder(root, arr, &index);  // Sorted array from BST

    int idx = 0;
    bstToMinHeap(root, arr, &idx);

    printf("Level order of converted Min Heap:\n");
    printLevelOrder(root);

    return 0;
}
