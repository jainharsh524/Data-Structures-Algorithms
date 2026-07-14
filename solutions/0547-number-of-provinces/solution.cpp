class Solution {
public:
    void dfs(vector<vector<int>>& adj_lst, vector<int>& visited, int node){
        visited[node] = 1;
        for(int nei: adj_lst[node]){
            if(visited[nei]==-1) dfs(adj_lst, visited, nei);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), -1);
        vector<vector<int>> adj_lst(isConnected.size());
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected[i].size();j++){
                if(i!=j&&isConnected[i][j]){
                    adj_lst[i].push_back(j);
                    adj_lst[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<visited.size();i++){
            if(visited[i]==-1){
                dfs(adj_lst, visited, i);
                count++;
            }
        }
        return count;
    }
};
