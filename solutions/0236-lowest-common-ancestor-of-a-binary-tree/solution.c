/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* a, struct TreeNode* b){
    if(root==NULL||root==a||root==b) return root;

    struct TreeNode* left = lowestCommonAncestor(root->left, a, b);
    struct TreeNode* right = lowestCommonAncestor(root->right, a, b);
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    else{
        return root;
    }
}
