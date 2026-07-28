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
    TreeNode *prev = NULL, *first = NULL, *second = NULL, *last = NULL;
    void inord(TreeNode* root){
        if(root==NULL) return;
        //keep the inorder same, just track the violations, either 2 adjacent nodes value will be swapped or you will find the 2nd violation and in that case swap the first and last'
        inord(root->left); 
        if(prev!=NULL&&prev->val>root->val){
            if(first==NULL){
                first = prev;
                second = root;
            }
            else last = root;
        }
        prev = root;
        inord(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inord(root);
        if(first&&last) swap(first->val, last->val);
        else swap(first->val, second->val);
    }
};
