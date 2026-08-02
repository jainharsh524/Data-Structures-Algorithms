class Solution {
public:
    int predict(vector<int>& piles, int l, int r, bool flag, vector<vector<vector<int>>>& dp){
        if(l>r) return 0;
        int left = 0;
        int right = 0;
        if(dp[l][r][flag]!=0) return dp[l][r][flag];
        if(flag){
            left = piles[l]+predict(piles, l+1, r, 1-flag, dp);
            right = piles[r]+predict(piles, l, r-1, 1-flag, dp);
            return dp[l][r][flag] = max(left, right);
        }
        else{
            left = -piles[l]+predict(piles, l+1, r, 1-flag, dp);
            right = -piles[r]+predict(piles, l, r-1, 1-flag, dp);
            return dp[l][r][flag] = min(left, right);
        }
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size(),vector<vector<int>>(piles.size(), vector<int>(2, 0)));
        int score = predict(piles, 0, piles.size()-1, true, dp);
        // cout<<score<<endl;
        return score>=0;
    }
};
