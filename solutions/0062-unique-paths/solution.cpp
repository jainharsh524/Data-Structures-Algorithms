class Solution {
public:
    int count(int m, int n, int r, int c, vector<vector<int>>& dp){
        if(r==(m-1)&&c==(n-1)) return 1;
        if(r>=m||c>=n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        else{
            int right = count(m, n, r, c+1, dp);
            int down = count(m, n, r+1, c, dp);
            return dp[r][c] = right+down;
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(m, n, 0, 0, dp);
    }
};
