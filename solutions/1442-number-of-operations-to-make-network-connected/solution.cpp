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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DS ds(n);
        int cntextras = 0;
        for(auto &edge : connections){
            if(ds.find_ult_par(edge[0]) == ds.find_ult_par(edge[1])) cntextras++;
            else ds.unionByRank(edge[0], edge[1]);
        }
        int cntc = 0;
        for(int i=0;i<n;i++){
            if(ds.find_ult_par(i)==i) cntc++;
        }
        int ans = cntc - 1;
        if(ans > cntextras) return -1;
        return ans;
    }
};
