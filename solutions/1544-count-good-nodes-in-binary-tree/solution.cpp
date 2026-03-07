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
    int countGood(TreeNode* root, int maxi, int count){
        if(root==NULL) return 0;
        if(root->val>=maxi){
            maxi = root->val;
            count++;
        }
        int left = countGood(root->left, maxi, 0);
        int right = countGood(root->right, maxi, 0);
        count = count+left+right;
        return count;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        else{
            int maxi = root->val;
            int count = 0;
            count = countGood(root, maxi, count);
            return count;
        }
    }
};
