class Solution {
public:
    int solve(vector<vector<int>>& triangle, int ind, int row, vector<vector<int>> &dp){
        if(row>=triangle.size()) return 0;
        if(dp[row][ind]!=INT_MAX) return dp[row][ind];
        else{
            int same = triangle[row][ind]+solve(triangle, ind, row+1, dp);
            int next = triangle[row][ind]+solve(triangle, ind+1, row+1, dp);
            return dp[row][ind] = min(same, next);
        }
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle[triangle.size()-1].size(), INT_MAX));
        return solve(triangle, 0, 0, dp);
    }
};
