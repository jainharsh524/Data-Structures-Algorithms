/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dia;
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int right = height(root->right);
        int left = height(root->left);
        dia = max(dia, left+right);
        return 1 + max(right, left);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return dia;
    }
};
