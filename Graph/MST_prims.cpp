#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<pair<int,int>> adj[]) {
    // {wt, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);

    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (visited[node] == 1) continue;
        visited[node] = 1;
        sum += wt;

        for (auto iterator : adj[node]) {
            int nn = iterator.first;   // neighbour
            int edwt = iterator.second; // weight
            if (!visited[nn]) {
                pq.push({edwt, nn});
            }
        }
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;  // number of vertices and edges

    vector<pair<int,int>> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt}); // undirected graph
    }

    cout << "Weight of MST: " << spanningTree(V, adj) << endl;
    return 0;
}
