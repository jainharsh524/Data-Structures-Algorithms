class Solution {
public:
    int cnt(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp){
        if(dp[r][c]!=-1)return dp[r][c];
        else{
            int maxi = 1;
            vector<int> drow = {0,1,0,-1};
            vector<int> dcol = {1,0,-1,0};
            for(int i = 0;i<4;i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr<matrix.size()&&nc<matrix[0].size()){
                    if(matrix[r][c]<matrix[nr][nc]){
                        int val = 1+cnt(matrix, nr, nc, dp);
                        maxi = max(val, maxi);
                    }
                }
            }
            return dp[r][c] = maxi;
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                cnt(matrix, i, j, dp);
            }
        }
        int maxi = 1;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                maxi = max(dp[i][j], maxi);
            }
        }
        return maxi;
    }
};
