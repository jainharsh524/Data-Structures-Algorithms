/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* a, struct TreeNode* b){
        if(root == NULL || root == a || root == b) return root;

        struct TreeNode* left = lowestCommonAncestor(root->left, a, b);
        struct TreeNode* right = lowestCommonAncestor(root->right, a, b);

        if(left && right) return root;
        return left ? left : right;
    }
};
