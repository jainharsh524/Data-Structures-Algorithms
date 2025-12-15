class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj_lst(n);
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj_lst[u].push_back(v);
            indeg[v]++;
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(indeg[i]==0){
                res.push_back(i);
            }
        }
        return res;
    }
};
