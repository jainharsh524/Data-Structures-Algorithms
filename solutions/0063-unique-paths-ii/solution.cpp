class Solution {
public:
    int count(vector<vector<int>>& obstacleGrid, int r, int c, vector<vector<int>>& dp){
        if(r>=obstacleGrid.size()||c>=obstacleGrid[0].size()) return 0;
        if(r==obstacleGrid.size()-1 && c==obstacleGrid[0].size()-1) return 1;
        if(obstacleGrid[r][c]==1) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        else{
            int right = count(obstacleGrid, r, c+1, dp);
            int down = count(obstacleGrid, r+1, c, dp);
            return dp[r][c] = right+down;
        }
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return count(obstacleGrid, 0, 0, dp);
    }
};
