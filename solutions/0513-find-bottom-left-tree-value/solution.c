#include <stdlib.h>

// Queue structure
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = malloc(sizeof(struct Queue));
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

int findBottomLeftValue(struct TreeNode* root) {
    struct Queue* q = createQueue(1000);
    enqueue(q, root);
    int leftmost = root->val;

    while (!isEmpty(q)) {
        int levelSize = q->size;
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            if (i == 0) leftmost = node->val; // First node in the level
            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
    }
    return leftmost;
}

