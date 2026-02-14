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
        queue<TreeNode* > q;
        vector<vector<int>> res;
        if(root==NULL) return res;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> val(size);
            for(int i = 0;i<size;i++){
                if(flag){
                    val[size-i-1] = q.front()->val;
                }
                else{
                    val[i] = q.front()->val;
                }
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                     q.push(q.front()->right);
                }
                q.pop();
            }
            if(flag) flag = false;
            else flag = true;
            res.push_back(val);
        }
        return res;
    }
};
