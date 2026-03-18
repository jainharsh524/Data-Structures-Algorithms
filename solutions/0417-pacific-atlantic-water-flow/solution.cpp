class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<int>>& vis){
        vis[r][c] = 1;
        int drow[4] = {0,1,0,-1};
        int dcol[4] = {1,0,-1,0};
        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];
            if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size()){
                if(!vis[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    dfs(nr, nc, heights, vis);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n= heights.size();
        int m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> res;
        // Pacific
        for(int i=0;i<n;i++) dfs(i,0,heights,pacific);
        for(int j=0;j<m;j++) dfs(0,j,heights,pacific);
        // Atlantic
        for(int i=0;i<n;i++) dfs(i,m-1,heights,atlantic);
        for(int j=0;j<m;j++) dfs(n-1,j,heights,atlantic);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
