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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        vector<vector<int>> res;
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp(sz);
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                int idx = flag ? sz - 1 - i : i;
                temp[idx] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            flag = !flag;
            res.push_back(temp);
        }
        return res;
    }
};
