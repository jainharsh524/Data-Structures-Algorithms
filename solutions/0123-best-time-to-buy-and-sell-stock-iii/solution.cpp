class Solution {
public:
    int calProfit(vector<int>& prices, int index, int buy, int tranLeft, vector<vector<vector<int>>>& dp){
        if(index == prices.size()) return 0;
        if(tranLeft == 0) return 0;
        if(dp[index][buy][tranLeft] != -1) return dp[index][buy][tranLeft];
        if(buy){
            int bought = -prices[index] + calProfit(prices, index + 1, 1 - buy, tranLeft, dp);
            int left = calProfit(prices, index + 1, buy, tranLeft, dp);
            return dp[index][buy][tranLeft] = max(bought, left);
        }
        else{
            int sold = prices[index] + calProfit(prices, index + 1, 1-buy, tranLeft - 1, dp);
            int hold = calProfit(prices, index + 1, buy, tranLeft, dp);
            return dp[index][buy][tranLeft] = max(sold, hold);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp
        (prices.size(), vector<vector<int>>
        (2, vector<int>(3, -1)));
        return calProfit(prices, 0, 1, 2, dp);
    }
};
