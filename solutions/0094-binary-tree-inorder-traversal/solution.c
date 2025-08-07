#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));  // allocate for up to 1000 nodes
    struct TreeNode** stack = (struct TreeNode**)malloc(1000 * sizeof(struct TreeNode*));
    int top = -1;
    *returnSize = 0;

    struct TreeNode* curr = root;
    
    while (curr || top != -1) {
        // Reach the leftmost node of the current node
        while (curr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        // Current must be NULL at this point
        curr = stack[top--];
        result[(*returnSize)++] = curr->val;
        // Visit the right subtree
        curr = curr->right;
    }

    free(stack);
    return result;
}

