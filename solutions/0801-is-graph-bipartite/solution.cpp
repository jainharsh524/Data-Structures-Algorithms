class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, vector<int> &visited, vector<int> &color, int clr){
        visited[node] = 1;
        color[node] = 1-clr;
        for(int &nei: graph[node]){
            if(!visited[nei]){
                if(!dfs(graph, nei, visited, color, color[node])) return false;
            }
            else if(color[nei]==color[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);
        vector<int> color(graph.size(), -1);
        for(int i = 0;i<graph.size();i++){
            if(!visited[i]){
                if(!dfs(graph, i, visited, color, 0)) return false;
            }
        }
        return true;
    }
};
