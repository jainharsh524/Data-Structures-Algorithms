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

int preorderIndex;
int inorderMap[6001]; // offset to handle negatives: value + 3000

struct TreeNode* build(int* preorder, int* inorder, int inStart, int inEnd) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preorderIndex++];
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = root->right = NULL;

    int idx = inorderMap[rootVal + 3000];
    root->left = build(preorder, inorder, inStart, idx - 1);
    root->right = build(preorder, inorder, idx + 1, inEnd);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    preorderIndex = 0;
    for (int i = 0; i < inorderSize; i++) {
        inorderMap[inorder[i] + 3000] = i;
    }
    return build(preorder, inorder, 0, inorderSize - 1);
}

