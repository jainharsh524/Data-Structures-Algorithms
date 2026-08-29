class Solution {
public:
    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k){
        unordered_map<TreeNode*,TreeNode*> parent;
        markParents(root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        visited[target]=true;
        vector<int> res;
        while(!q.empty()){
            auto [node,dist]=q.front();
            q.pop();
            if(dist==k){
                res.push_back(node->val);
                continue;
            }
            if(node->left && !visited[node->left]){
                visited[node->left]=true;
                q.push({node->left,dist+1});
            }
            if(node->right && !visited[node->right]){
                visited[node->right]=true;
                q.push({node->right,dist+1});
            }
            if(parent[node] && !visited[parent[node]]){
                visited[parent[node]]=true;
                q.push({parent[node],dist+1});
            }
        }
        return res;
    }
};
