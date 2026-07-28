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
    struct custom{
        int mini;
        int maxi;
        int maxsize;
        custom(int a, int b, int c){
            this->mini = a;
            this->maxi = b;
            this->maxsize = c;
        }
    };
    int max_sum = INT_MIN;
    custom maxsum(TreeNode* root){
        if(root==NULL) return custom(INT_MAX, INT_MIN, 0);
        custom LST = maxsum(root->left);
        custom RST = maxsum(root->right);
        //this would be our condition to validate the BST
        if(LST.maxi<root->val && RST.mini>root->val){
            max_sum = max(max_sum, LST.maxsize+RST.maxsize+root->val); // if question asks you about the max sized BST then just don't add the root->val, add 1 istead of it;
            return custom(min(root->val, LST.mini), max(root->val, RST.maxi), LST.maxsize+RST.maxsize+root->val);
        }
        return custom(INT_MIN, INT_MAX, 0);
    }
    int maxSumBST(TreeNode* root) {
        custom node = maxsum(root);
        return (max_sum<0)?0: max_sum;
    }
};
