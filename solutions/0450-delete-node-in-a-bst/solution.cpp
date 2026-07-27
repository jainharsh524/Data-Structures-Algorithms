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
    bool isLeaf(TreeNode* root){
        return !root->left&&!root->right;
    }
    void deletion(TreeNode* root, TreeNode* parent, int key){
        if(root==NULL) return;
        if(root->val==key){
            if(isLeaf(root)){
                if(parent->val<key) parent->right = NULL;
                else parent->left = NULL;
            }
            else if(!root->left){
                if(parent->val<key) parent->right = root->right;
                else parent->left = root->right;
            }
            else if(!root->right){
                if(parent->val<key) parent->right = root->left;
                else parent->left = root->left;
            }
            else{
                TreeNode* leftSubtree=root->left;
                TreeNode* rightSubtree=root->right;
                TreeNode* curr=leftSubtree;
                while(curr->right)curr=curr->right;
                curr->right=rightSubtree;
                if(parent->val<key)parent->right=leftSubtree;
                else parent->left=leftSubtree;
            }
        }
        else if(root->val<key) deletion(root->right, root, key);
        else if(root->val>key) deletion(root->left, root, key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        else if(root->val==key){
            if(isLeaf(root)) return NULL;
            else if(!root->left) return root->right;
            else if(!root->right) return root->left;
            else{
                TreeNode* leftSubtree=root->left;
                TreeNode* rightSubtree=root->right;
                TreeNode* curr=leftSubtree;
                while(curr->right)curr=curr->right;
                curr->right=rightSubtree;
                return leftSubtree;
            }
        }
        deletion(root, NULL, key);
        return root;
    }
};
