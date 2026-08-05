class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<int>& sus, vector<vector<int>> &adj_lst){
        visited[node] = 1;
        sus.push_back(node);
        for(int ele: adj_lst[node]){
            if(!visited[ele]) dfs(ele, visited, sus, adj_lst);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj_lst(n);
        for(int i = 0;i<invocations.size();i++){
            adj_lst[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> sus;
        vector<int> visited(n, 0);
        dfs(k, visited, sus, adj_lst);
        unordered_set<int> suset(sus.begin(), sus.end());
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(suset.find(i)==suset.end()){
                for(int ele: adj_lst[i]){
                    if(suset.find(ele)!=suset.end()){
                        flag = true; break;
                    }
                }
            }
        }
        vector<int> res;
        if(!flag){
            for(int i = 0;i<n;i++){
                if((suset.find(i)==suset.end()))res.push_back(i);
            }
        }
        else{
            res.resize(n);
            for(int i = 0;i<n;i++){
                res[i] = i;
            }
        }
        return res;
    }
};
