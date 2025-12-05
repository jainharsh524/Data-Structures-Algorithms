#include <iostream>
#include <vector>
#include <algorithm>
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
        if(ult_par_u == ult_par_v) return;

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
    int V, E;
    cin >> V >> E; // Number of vertices and edges
    disjoint_set ds(V);

    vector<pair<int, pair<int,int>>> edges;

    // Input edges: u v wt
    for(int i=0;i<E;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, {u, v}});
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    int mstWt = 0;
    vector<pair<int,int>> mstEdges;

    // Kruskal’s algorithm
    for(auto edge: edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if(ds.find_ult_par(u) != ds.find_ult_par(v)){
            mstWt += wt;
            mstEdges.push_back({u,v});
            ds.unionByRank(u, v);
        }
    }

    cout << "MST Weight = " << mstWt << "\n";
    cout << "Edges in MST:\n";
    for(auto e: mstEdges){
        cout << e.first << " -> " << e.second << "\n";
    }

    return 0;
}
