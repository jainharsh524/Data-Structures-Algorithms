class DSU{
    public:
        vector<int> rank, parent;
        DSU(int n){
            rank.resize(n, 0);
            parent.resize(n);
            for(int i = 0; i< n;i++) parent[i] = i;
        }
        int find_ult_par(int u){
            if(parent[u] != u){
                parent[u] = find_ult_par(parent[u]);
            }
            return parent[u];
        }
        void unionByRank(int u, int v){
            int ultu = find_ult_par(u);
            int ultv = find_ult_par(v);
            if(ultu == ultv) return;
            if(rank[ultu] > rank[ultv]){
                parent[ultv] = ultu;
            }
            else if(rank[ultu] < rank[ultv]){
                parent[ultu] = ultv;
            }
            else{ 
                parent[ultu] = ultv;
                rank[ultv]++;
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mR = INT_MIN;
        int mC = INT_MIN;
        for(auto ele: stones){
            mR = max(mR, ele[0]);
            mC = max(mC, ele[1]);
        }
        DSU ds(mR + mC + 2);
        unordered_map<int, int> par;
        for(auto ele: stones){
            int r = ele[0];
            int c = ele[1];
            c += mR + 1;
            ds.unionByRank(r, c);
            par[r] = 1;
            par[c] = 1;
        }
        int cnt = 0;
        for(int i = 0; i < (mR + mC + 2); i++){
            if(par.find(i) != par.end()){
                if(ds.parent[i] == i) cnt++;
            }
        }
        return stones.size() - cnt;
    }
};
