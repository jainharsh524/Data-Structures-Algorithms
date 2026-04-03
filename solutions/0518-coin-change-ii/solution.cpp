class Solution {
public:
    int solve(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
        if(amount == 0) return 1;
        if(amount < 0) return 0;
        if(index == coins.size()) return 0;

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int take = solve(coins, index, amount - coins[index], dp);
        int skip = solve(coins, index + 1, amount, dp);

        return dp[index][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(coins, 0, amount, dp);
    }
};
