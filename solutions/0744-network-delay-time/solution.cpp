class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        for (int i = 0; i < n - 1; i++) {
            for (auto &e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

