/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode** queue = malloc(2000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    // Result storage
    int** results = malloc(2000 * sizeof(int*));
    int* colSizes = malloc(2000 * sizeof(int));
    *returnSize = 0;
    *returnColumnSizes = colSizes;

    bool leftToRight = true;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int* level = malloc(levelSize * sizeof(int));

        // Gather one level's values
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];
            int idx = leftToRight ? i : (levelSize - 1 - i);
            level[idx] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        results[*returnSize] = level;
        colSizes[*returnSize] = levelSize;
        (*returnSize)++;
        leftToRight = !leftToRight;
    }

    free(queue);
    return results;
}

