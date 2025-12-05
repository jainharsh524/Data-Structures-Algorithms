#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int src) {
    // Min-heap (dist, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(V, INT_MAX);

    distance[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Skip if this is not the latest distance
        // if (dist > distance[node]) continue;

        for (auto &it : adj[node]) {
            int adjnode = it.first;
            int wt = it.second;

            if (distance[adjnode] > dist + wt) {
                distance[adjnode] = dist + wt;
                pq.push({distance[adjnode], adjnode});
            }
        }
    }
    return distance;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<pair<int,int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if graph is undirected
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(V, adj, src);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
