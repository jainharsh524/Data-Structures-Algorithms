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
    int maxsum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        int left = max(0, maxsum(root->left, maxi));
        int right = max(0, maxsum(root->right, maxi));
        maxi = max(maxi, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = -1000;
        maxsum(root, maxi);
        return maxi;
    }
};
