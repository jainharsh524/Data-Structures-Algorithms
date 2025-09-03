#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored

        for (int i = 0; i < n; ++i) {
            if (color[i] != -1) continue;
            queue<int> q;
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: graph[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

