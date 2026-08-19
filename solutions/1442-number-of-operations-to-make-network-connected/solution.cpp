class Solution {
public:
    struct DSU{
        vector<int> parent, rank;
        DSU(int n){
            parent.resize(n);
            rank.resize(n, 0);
            int i = 0;
            for(int &ele: parent){
                ele = i;
                i++;
            }
        }

        int find_ult_par(int node){
            if(parent[node] != node){
                parent[node] = find_ult_par(parent[node]);
            }
            return parent[node];
        }

        void union_by_rank(int u, int v){
            int ultu = find_ult_par(u);
            int ultv = find_ult_par(v);

            if(ultu == ultv) return;

            if(rank[ultu] < rank[ultv]){
                parent[ultu] = ultv;
            }
            else if(rank[ultu] > rank[ultv]){
                parent[ultv] = ultu;
            }
            else{
                parent[ultv] = ultu;
                rank[ultu]++;
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        DSU DS(n);
        int comp = n;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(DS.find_ult_par(u) != DS.find_ult_par(v)){
                DS.union_by_rank(u, v);
                comp--;
            }
        }
        return comp - 1;
    }
};
