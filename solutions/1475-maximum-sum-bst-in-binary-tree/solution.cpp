/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    struct customcheck {
        int maxi, mini, maxsum;
        customcheck(int maxi, int mini, int maxsum) {
            this->maxi = maxi;
            this->mini = mini;
            this->maxsum = maxsum;
        }
    };
    int max_sum = 0;
    customcheck* maxsummation(TreeNode* root) {
        if (root == nullptr)
            return new customcheck(INT_MIN, INT_MAX, 0);
        customcheck* ls = maxsummation(root->left);
        customcheck* rs = maxsummation(root->right);
        if (ls->maxi < root->val && root->val < rs->mini) {
            max_sum = max(max_sum, ls->maxsum + rs->maxsum + root->val);
            return new customcheck(max(root->val, rs->maxi),
                                   min(root->val, ls->mini),
                                   ls->maxsum + rs->maxsum + root->val);
        } else {
            return new customcheck(INT_MAX, INT_MIN, 0);
        }
    }
    int maxSumBST(TreeNode* root) {
        maxsummation(root);
        return max_sum;
    }
};
