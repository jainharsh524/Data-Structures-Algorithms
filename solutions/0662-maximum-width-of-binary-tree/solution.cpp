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
    int widthOfBinaryTree(TreeNode* root) {
        // queue <pair<pair<TreeNode*, int>, int>> q;
        // vector<pair<int, int>> mp(100000);
        // q.push({{root, 0}, 0});
        // int offset = 500;
        // int minlvl = 50000;
        // int maxlvl = -10000;
        // while(!q.empty()){
        //     int size = q.size();
        //     for(int i= 0;i<size;i++){
        //         TreeNode* nd = q.front().first.first;
        //         int lvl = q.front().first.second;
        //         int h = q.front().second;
        //         q.pop();
        //         minlvl = min(minlvl, lvl);
        //         maxlvl = max(maxlvl, lvl);
        //         mp[offset+lvl] = {nd->val, h};
        //         if(nd->left){
        //             q.push({{nd->left, lvl-1}, h+1});
        //         }
        //         if(nd->right){
        //             q.push({{nd->right, lvl+1}, h+1});
        //         }

        //     }
        // }
        // int i = offset+minlvl;
        // int j = offset+maxlvl;
        // while(i<j){
        //     if(mp[i].second==mp[j].second){
        //         return j-i;
        //     }
        //     else if(mp[i].second>mp[j].second){
        //         i++;
        //     }
        //     else j--;
        // }
        // return 0;
        if(root==NULL) return 0;
        int mw = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int s = q.size();
            int start = q.front().second;
            int end = q.back().second;
            mw = max(mw, end-start+1);
            for(int i = 0;i<s;i++){
                TreeNode* nd = q.front().first;
                int ind = q.front().second - start;
                q.pop();
                if(nd->left) q.push({nd->left, ind*2LL+1});
                if(nd->right) q.push({nd->right, ind*2LL+2});
            }
        }
        return mw;
    }
};
