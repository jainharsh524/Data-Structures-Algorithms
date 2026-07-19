class Solution {
public:
    int solve(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) { 
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(index == coins.size()) return INT_MAX; 
        if(dp[index][amount] != -1) 
            return dp[index][amount];
 
        int take = solve(coins, index, amount - coins[index], dp);
        if(take != INT_MAX) take = take + 1; 
        int skip = solve(coins, index + 1, amount, dp); 
        return dp[index][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
