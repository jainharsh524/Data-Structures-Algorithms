class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int node, vector<int> &visited){
        visited[node] = 1;
        for(int i = 0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1){
                if(visited[i]!=1){
                    dfs(isConnected, i, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected.size(), 0);
        int count = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(visited[i]!=1){
                count++;
                dfs(isConnected, i, visited);
            }
        }return count;
    }
};
