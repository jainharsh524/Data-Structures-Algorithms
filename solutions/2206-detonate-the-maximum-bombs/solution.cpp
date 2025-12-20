class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;
        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(nei, visited, adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build directed graph
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x2 - x1;
                long long dy = y2 - y1;
                if (dx*dx + dy*dy <= r1*r1) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxDet = 0;

        // Try DFS from every bomb
        for (int i = 0; i < n; i++) {
            vector<int> visited(n, 0);
            dfs(i, visited, adj);
            int detonated = count(visited.begin(), visited.end(), 1);
            maxDet = max(maxDet, detonated);
        }

        return maxDet;
    }
};

