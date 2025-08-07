/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;

    // Allocate memory for result and stack
    int* result = malloc(1000 * sizeof(int));  // Adjust size as needed
    struct TreeNode** stack = malloc(1000 * sizeof(struct TreeNode*));
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        result[(*returnSize)++] = node->val;

        // Push right first so left is processed first
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }

    free(stack);
    return result;
}

