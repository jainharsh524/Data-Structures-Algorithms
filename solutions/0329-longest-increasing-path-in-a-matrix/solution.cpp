class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>&dp){
        if(dp[r][c]!=-1)return dp[r][c];
        int mr[] = {1,0,-1,0};
        int mc[] = {0,1,0,-1};
        int best = 1;
        for(int i =0;i<4;i++){
            int nr = r+mr[i];
            int nc = c+mc[i];
            if(nr>=0&&nc>=0&&nr<matrix.size()&&nc<matrix[0].size()&&matrix[r][c]<matrix[nr][nc]){
                best = max(best, 1+dfs(matrix, nr, nc, dp));
            }
        }
        dp[r][c] = best;
        return best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>>dp;
        dp.assign(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int a = 0;a<matrix.size();a++){
            for(int b = 0;b<matrix[0].size();b++){
                dfs(matrix, a, b, dp);
            }
        }
        int max = 0;
        for(int a = 0;a<matrix.size();a++){
            for(int b = 0;b<matrix[0].size();b++){
                if(max<dp[a][b]){
                    max = dp[a][b];
                }
            }
        }
        return max;
    }
};
