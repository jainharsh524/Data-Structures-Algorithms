/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

#define MAXN 3000

int postIndex;
int inorderMap[6001]; // Offset array to handle negative node values

struct TreeNode* dfs(int* inorder, int* postorder, int inStart, int postStart, int n) {
    if (n <= 0) return NULL;
    int rootVal = postorder[postStart + n - 1];
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int idx = inorderMap[rootVal + MAXN];
    int leftSize = idx - inStart;

    root->left = dfs(inorder, postorder, inStart, postStart, leftSize);
    root->right = dfs(inorder, postorder, idx + 1, postStart + leftSize, n - leftSize - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i] + MAXN] = i;
    }
    return dfs(inorder, postorder, 0, 0, inorderSize);
}

