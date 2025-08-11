/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* flattenTree(struct TreeNode* root) {
    if (root == NULL) return NULL;
    struct TreeNode* leftTail = flattenTree(root->left);
    struct TreeNode* rightTail = flattenTree(root->right);

    if (leftTail) {
        leftTail->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    // Return the rightmost node after flattening
    return rightTail ? rightTail : (leftTail ? leftTail : root);
}

void flatten(struct TreeNode* root) {
    flattenTree(root);
}
