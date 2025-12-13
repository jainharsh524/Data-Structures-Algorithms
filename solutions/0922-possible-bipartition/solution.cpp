class Solution {
public:
    bool dfs(int source, vector<vector<int>>& adj, vector<int>& color) {
        for (int nei : adj[source]) {
            if (color[nei] == -1) {
                color[nei] = 1 - color[source]; // opposite color
                if (!dfs(nei, adj, color)) return false;
            }
            else if (color[nei] == color[source]) {
                return false;   // conflict: same color on adjacent nodes
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);

        // Build undirected graph
        for (auto &d : dislikes) {
            int u = d[0] - 1;
            int v = d[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);

        // Try to color each connected component
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                color[i] = 0; // start with color 0
                if (!dfs(i, adj, color)) return false;
            }
        }

        return true;
    }
};

