#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Initialize queue with rotten oranges and count fresh ones
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        if (fresh == 0) return 0;  // No fresh oranges to rot
        
        int minutes = 0;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        
        // BFS: spread rot minute by minute
        while (!q.empty() && fresh > 0) {
            minutes++;
            int qs = q.size();
            while (qs--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = x + dirs[d];
                    int ny = y + dirs[d+1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return fresh == 0 ? minutes : -1;
    }
};

