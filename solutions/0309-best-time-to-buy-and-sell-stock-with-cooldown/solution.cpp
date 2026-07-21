class Solution {
public:
    int calProfit(vector<int>& prices, int index, int buy, int cold, vector<vector<vector<int>>>& dp){
        if(index==prices.size()) return 0;
        int profit = 0;
        if(dp[index][buy][cold]!=-1) return dp[index][buy][cold];
        if(cold){
            profit = calProfit(prices, index+1, buy, 1-cold, dp);
        }
        else if(buy&&!cold){
            profit = max(-prices[index]+calProfit(prices, index+1, 1-buy, cold, dp), calProfit(prices, index+1, buy, cold, dp));
        }
        else if(!buy&&!cold){
            profit = max(prices[index]+calProfit(prices, index+1, 1-buy, 1-cold, dp), calProfit(prices, index+1, buy, cold, dp));
        }
        return dp[index][buy][cold] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return calProfit(prices, 0, 1, 0, dp);
    }
};
