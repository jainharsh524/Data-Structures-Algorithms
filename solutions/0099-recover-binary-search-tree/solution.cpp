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
    TreeNode* prev = nullptr;
    TreeNode *first = nullptr, *sec = nullptr, *last = nullptr;
    void checkIn(TreeNode* root){
        if(root==nullptr) return;
        checkIn(root->left);
        if(prev){
            if(prev->val>root->val){
                if(!first){
                    first = prev;
                    sec = root;
                }
                else{
                    last = root;
                }
            }
        }
        prev = root;
        checkIn(root->right);
    }
    void recoverTree(TreeNode* root) {
        checkIn(root);
        if(last){
            swap(first->val, last->val);
        }
        else{
            swap(first->val, sec->val);
        }
    }
};
