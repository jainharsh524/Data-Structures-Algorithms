class Solution {
public:
    void dfs(vector<int> &visited, vector<vector<int>> &adj_lst, int source){
        visited[source] = 1;
        for(int nei: adj_lst[source]){
            if(!visited[nei]){
                dfs(visited, adj_lst, nei);
            }
        }
    }
    int find_ult_par(vector<int> &parent, int node){
        if(parent[node]==node) return parent[node];
        else return parent[node] = find_ult_par(parent, parent[node]);
    }
    bool union1(vector<int> &rank, vector<int> &parent, int u, int v){
        int ultu = find_ult_par(parent, u);
        int ultv = find_ult_par(parent, v);
        if(ultu == ultv) {
            return true;
        }
        else if(rank[ultu]<rank[ultv]){
            parent[ultu] = ultv;
        }
        else if(rank[ultu]>rank[ultv]){
            parent[ultv] = ultu;
        }
        else{
            rank[ultu]++;
            parent[ultv] = ultu;
        }
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;
        vector<int> visited(n,0);
        vector<vector<int>> adj_lst(n);
        for(int i = 0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj_lst[u].push_back(v);
            adj_lst[v].push_back(u);
        }
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                dfs(visited, adj_lst, i);
                count++;
            }
        }
        vector<int> rank(n, 0);
        vector<int> parent(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        int count1 = 0;
        for(int i =0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(union1(rank, parent, u, v)){
                count1++;
            }
        }
        if(n-1>connections.size()){
            return -1;
        }
        else return count-1;
    }
};
