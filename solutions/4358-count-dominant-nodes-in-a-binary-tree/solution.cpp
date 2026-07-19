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
    bool check(TreeNode* root, int value){
        if(root == nullptr) return true;
        if(root->val > value) return false;
        return check(root->left, value) && check(root->right, value);
    }
    int countDominantNodes(TreeNode* root){
        if(root == nullptr) return 0;
        int cnt = 0;
        if(check(root, root->val)) cnt++;
        cnt += countDominantNodes(root->left);
        cnt += countDominantNodes(root->right);
        return cnt;
    }
};
