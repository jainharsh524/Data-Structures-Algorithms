class Solution {
public:
    int calCherry(vector<vector<int>>& g,
                 vector<vector<vector<int>>>& dp,
                 int r, int c, int c1){
        int n = g.size();
        int m = g[0].size();
        if(c < 0 || c >= m || c1 < 0 || c1 >= m) return -1e9;
        if(r == n-1){
            if(c == c1) return g[r][c];
            return g[r][c] + g[r][c1];
        }
        if(dp[r][c][c1] != -1) return dp[r][c][c1];
        int ans = 0;
        vector<int> dc = {-1, 0, 1};
        for(int i=0;i<3;i++){
            int nc = c + dc[i];
            for(int j=0;j<3;j++){
                int nc1 = c1 + dc[j];
                int choco;
                if(c == c1) choco = g[r][c];
                else choco = g[r][c] + g[r][c1];
                choco += calCherry(g, dp, r+1, nc, nc1);
                ans = max(ans, choco);
            }
        }
        return dp[r][c][c1] = ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return calCherry(g, dp, 0, 0, m-1);
    }
};

