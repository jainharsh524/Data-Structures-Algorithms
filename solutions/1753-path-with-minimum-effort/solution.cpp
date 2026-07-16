class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0][0] = 0;
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};
        while(!pq.empty()){
            auto p = pq.top();
            int diff = p[0];
            int r = p[1];
            int c = p[2];
            pq.pop();
            if(r==n-1 && c==m-1){
                return diff;
            }
            if(dist[r][c]<diff) continue;
            for(int k = 0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(dist[r][c]!=1e9 && dist[nr][nc]>max(dist[r][c], abs(heights[nr][nc]-heights[r][c]))){
                        dist[nr][nc] = max(dist[r][c], abs(heights[nr][nc]-heights[r][c]));
                        pq.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return -1;
    }
};
