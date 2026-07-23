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
    void newPaths(TreeNode* root, string res, vector<string> &ans){
        // if(root==NULL) return res;
        if(!root->left&&!root->right){
            res = res+to_string(root->val)+"";
            ans.push_back(res);
            return;
        }
        else{
            res = res+to_string(root->val)+"->";
            if(root->left) newPaths(root->left, res, ans);
            if(root->right) newPaths(root->right, res, ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string res = "";
        if(root==NULL) return paths;
        else{
            newPaths(root, res, paths);
        }
        return paths;
    }
};
