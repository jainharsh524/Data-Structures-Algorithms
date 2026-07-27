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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(true){
            if(curr->right&&curr->val<=val) curr = curr->right;
            else if(curr->left&&curr->val>val) curr = curr->left;
            else if(!curr->right&&curr->val<=val){ curr->right = new TreeNode(val); break;}
            else if(!curr->left&&curr->val>val){ curr->left = new TreeNode(val); break;}
        }
        return root;
    }
};
