class DS{
public:
    vector<int> rank, parent;
    DS(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find_ult_par(int node){
        if(node==parent[node]) return node;
        return parent[node]=find_ult_par(parent[node]);
    }
    void unionByRank(int u,int v){
        int pu=find_ult_par(u);
        int pv=find_ult_par(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxR = 0;
        int maxC = 0;
        for(auto ele: stones){
            maxR = max(maxR, ele[0]);
            maxC = max(maxC, ele[1]);
        }
        DS ds(maxR+maxC+2);
        unordered_map<int, int> stoneNodes;
        for(auto ele: stones){
            int r = ele[0];
            int c = ele[1]+maxR+1;
            ds.unionByRank(r, c);
            stoneNodes[r] = 1;
            stoneNodes[c] = 1;
        }
        int cnt = 0;
        for(auto ele: stoneNodes){
            if(ds.find_ult_par(ele.first)==ele.first) cnt++;
        }
        return stones.size()-cnt;
    }
};
