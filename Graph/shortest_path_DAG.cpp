#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

void topo_sort(int node, vector<pair<int, int>> adj_lst[], vector<int> &visited, stack<int> &st) {
    visited[node] = 1;
    for (auto iterator : adj_lst[node]) {
        if (!visited[iterator.first]) {
            topo_sort(iterator.first, adj_lst, visited, st);
        }
    }
    st.push(node);
}

vector<int> shortest_path(int N, int M, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj_lst[N];
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj_lst[u].push_back({v, w});
    }

    // get the topo sort
    vector<int> visited(N, 0);
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) topo_sort(i, adj_lst, visited, st);
    }

    // distance array
    vector<int> distance(N, INT_MAX);
    distance[0] = 0; // assuming source = 0

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (distance[node] != INT_MAX) {
            for (auto iterator : adj_lst[node]) {
                int v = iterator.first;
                int wt = iterator.second;
                if (distance[node] + wt < distance[v]) {
                    distance[v] = distance[node] + wt;
                }
            }
        }
    }
    return distance;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges(M, vector<int>(3));

    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> dist = shortest_path(N, M, edges);

    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
