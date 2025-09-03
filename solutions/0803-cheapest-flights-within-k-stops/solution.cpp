class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = INT_MAX / 2;
        vector<int> dist(n, INF), temp(n);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            temp = dist;
            for (auto &f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }
            dist = temp;
        }

        return (dist[dst] >= INF) ? -1 : dist[dst];
    }
};

