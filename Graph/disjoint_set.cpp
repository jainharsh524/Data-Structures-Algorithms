#include<iostream>
#include<vector>
using namespace std;

class disjoint_set {
    vector<int> rank, parent;

public:
    disjoint_set(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;  // initialize parent[i] = i
        }
    }

    int find_ult_par(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = find_ult_par(parent[node]); // path compression
    }

    void unionByRank(int u, int v) {
        int ult_par_u = find_ult_par(u);
        int ult_par_v = find_ult_par(v);
        if(ult_par_u == ult_par_v) {
            return;
        }
        if(rank[ult_par_u] < rank[ult_par_v]) {
            parent[ult_par_u] = ult_par_v;
        }
        else if(rank[ult_par_u] > rank[ult_par_v]) {
            parent[ult_par_v] = ult_par_u;
        }
        else {
            parent[ult_par_v] = ult_par_u;
            rank[ult_par_u]++;
        }
    }
};

int main() {
    int V;
    cin >> V;
    disjoint_set ds(V);

    // Example usage
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    ds.unionByRank(3,7);

    if(ds.find_ult_par(1) == ds.find_ult_par(3)) {
        cout << "1 and 3 belong to the same set\n";
    } else {
        cout << "1 and 3 are in different sets\n";
    }

    return 0;
}
