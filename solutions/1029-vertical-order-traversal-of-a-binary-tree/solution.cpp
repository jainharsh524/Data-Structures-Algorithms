class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> q;
        // node, {row, col}
        q.push({root, {0, 0}});
        vector<vector<pair<int,int>>> res(2002);
        int offset = 1001;
        int mini = offset, maxi = offset;
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            res[offset + col].push_back({row, curr->val});
            mini = min(mini, offset + col);
            maxi = max(maxi, offset + col);
            if(curr->left) q.push({curr->left, {row + 1, col - 1}});
            if(curr->right) q.push({curr->right, {row + 1, col + 1}});
        }
        vector<vector<int>> ans;
        for(int i = mini; i <= maxi; i++){
            sort(res[i].begin(), res[i].end(),
                 [](pair<int,int> &a, pair<int,int> &b){
                     if(a.first == b.first)
                         return a.second < b.second;
                     return a.first < b.first;
                 });
            vector<int> temp;
            for(auto &x : res[i]) temp.push_back(x.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
