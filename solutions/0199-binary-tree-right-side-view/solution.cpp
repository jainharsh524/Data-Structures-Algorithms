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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            TreeNode* nd = NULL;
            for(int i = 0;i<size;i++){
                nd = q.front();
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
                q.pop();
            }
            res.push_back(nd->val);
        }
        return res;
    }
};
