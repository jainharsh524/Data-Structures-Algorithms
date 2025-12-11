class DS{
    public:
        vector<int> rank, parent;
        DS(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            for(int i = 0;i<n+1;i++){
                parent[i] = i;
            }
        }
        int find_ult_par(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = find_ult_par(parent[node]);
        }
        vector<int> union_by_rank(int u, int v){
            int paru = find_ult_par(u);
            int parv = find_ult_par(v);
            vector<int> res;
            if(paru==parv){
                res.push_back(u);
                res.push_back(v);
            }
            else if(rank[paru]>rank[parv]){
                parent[parv] = paru;
            }
            else if(rank[parv]>rank[paru]){
                parent[paru] = parv;
            }
            else{
                parent[paru] = parv;
                rank[parv]++;
            }
            return res;
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DS d(edges.size());
        vector<int> result;
        for(int i = 0;i<edges.size();i++){
            vector<int> res = d.union_by_rank(edges[i][0], edges[i][1]);
            if(res.size()!=0){
                result = res;
            }
        }
        return result;
    }
};
