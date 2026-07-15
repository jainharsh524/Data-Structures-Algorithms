class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int clr, vector<int>& color){
        color[node] = clr;
        for(int nei : graph[node]){
            if(color[nei] == -1){
                if(!dfs(graph, nei, 1 - clr, color)) return false;
            }
            else if(color[nei] == clr) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!dfs(graph, i, 0, color))
                    return false;
            }
        }
        return true;
    }
};
