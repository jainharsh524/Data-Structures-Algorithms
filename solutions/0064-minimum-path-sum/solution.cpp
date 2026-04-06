class Solution {
public:
    int count(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        if(r>=grid.size()||c>=grid[0].size()) return 1e9;
        if(r==grid.size()-1 && c==grid[0].size()-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        else{
            int right = grid[r][c]+count(grid, r, c+1, dp);
            int down = grid[r][c]+count(grid, r+1, c, dp);
            return dp[r][c] = min(right, down);
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return count(grid, 0, 0, dp);
    }
};
