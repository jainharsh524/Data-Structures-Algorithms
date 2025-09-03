#include <vector>
#include <cmath>
#include <limits>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
        
        vector<int> dist(n, numeric_limits<int>::max());
        vector<bool> inMST(n, false);
        dist[0] = 0;  // Start from point 0
        
        int totalCost = 0;
        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && (u == -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            
            inMST[u] = true;
            totalCost += dist[u];
            
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int cost = abs(points[u][0] - points[v][0]) +
                               abs(points[u][1] - points[v][1]);
                    dist[v] = min(dist[v], cost);
                }
            }
        }
        
        return totalCost;
    }
};

