/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdlib.h>

struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = malloc(sizeof(*q));
    q->data = malloc(sizeof(struct TreeNode*) * capacity);
    q->front = q->rear = q->size = 0;
    q->capacity = capacity;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
    q->rear %= q->capacity;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->data[q->front++];
    q->front %= q->capacity;
    q->size--;
    return node;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *result = malloc(sizeof(int) * 101);
    *returnSize = 0;
    struct Queue* q = createQueue(200);
    enqueue(q, root);

    while (!isEmpty(q)) {
        int levelSize = q->size;
        struct TreeNode* node = NULL;
        for (int i = 0; i < levelSize; i++) {
            node = dequeue(q);
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        result[(*returnSize)++] = node->val;  // last node is rightmost
    }

    return result;
}

