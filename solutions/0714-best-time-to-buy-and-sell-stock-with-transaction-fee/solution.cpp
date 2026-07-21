class Solution {
public:
    int calProfit(vector<int>& prices, int index, int buy, vector<vector<int>>& dp, int fee){
        if(index==prices.size()) return 0;
        int profit = 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            profit = max(-prices[index] + calProfit(prices, index+1, 1-buy, dp, fee), calProfit(prices, index+1, buy, dp, fee));
        }
        else{
            profit = max(prices[index] + calProfit(prices, index+1, 1-buy, dp, fee) - fee, calProfit(prices, index+1, buy, dp, fee));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return calProfit(prices, 0, 1, dp, fee);
    }
};
