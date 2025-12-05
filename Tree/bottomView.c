#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct treeNode {
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

struct queueNode {
    struct treeNode* n;
    int hrizon_dist;
};

int* bottomview(struct treeNode* root, int* returnsize) {
    if (root == NULL) {
        *returnsize = 0;
        return NULL;
    }

    int minHd = INT_MAX, maxHd = INT_MIN;
    int map[1001];
    int off = 500;

    struct queueNode queue[10000];
    int rear = 0, front = 0;

    struct queueNode temp;
    temp.n = root;
    temp.hrizon_dist = 0;
    queue[rear++] = temp;

    while (front < rear) {
        temp = queue[front++];
        struct treeNode* n = temp.n;
        int hd = temp.hrizon_dist;

        // Update map for bottom view
        map[hd + off] = n->val;
        if (hd < minHd) minHd = hd;
        if (hd > maxHd) maxHd = hd;

        if (n->left) {
            struct queueNode leftNode;
            leftNode.n = n->left;
            leftNode.hrizon_dist = hd - 1;
            queue[rear++] = leftNode;
        }

        if (n->right) {
            struct queueNode rightNode;
            rightNode.n = n->right;
            rightNode.hrizon_dist = hd + 1;
            queue[rear++] = rightNode;
        }
    }

    int size = maxHd - minHd + 1;
    int* result = (int*)malloc(size * sizeof(int));
    *returnsize = size;

    for (int i = 0; i < size; i++) {
        result[i] = map[minHd + i + off];
    }

    return result;
}
