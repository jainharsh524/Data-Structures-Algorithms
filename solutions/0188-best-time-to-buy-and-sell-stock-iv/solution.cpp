class Solution {
public:
    int func(int i, vector<int>& prices, int buy,vector<vector<vector<int>>>&dp, int c){
        if(i==prices.size() || c==0){
            return 0;
        }
        if(dp[i][buy][c]!=-1){
            return dp[i][buy][c];
        }
        if(buy){
            return dp[i][buy][c]=max(-prices[i]+func(i+1,prices,0,dp,c),
                        0+func(i+1,prices,1,dp,c));
        }
        else{
            return dp[i][buy][c]=max(prices[i]+func(i+1,prices,1,dp,c-1),
                        0+func(i+1,prices,0,dp,c));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return func(0,prices,1,dp,k);
    }
};
