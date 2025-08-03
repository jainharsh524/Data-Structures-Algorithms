#include <stdio.h>
#include <string.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int dp[301][10001];

int solve(int i, int* coins, int amount) {
    if (amount == 0) return 0;
    if (i < 0) return INT_MAX - 1;

    if (dp[i][amount] != -1) return dp[i][amount];

    int notTake = solve(i - 1, coins, amount);
    int take = INT_MAX - 1;
    if (coins[i] <= amount) {
        take = 1 + solve(i, coins, amount - coins[i]); // Can reuse coin i
    }

    dp[i][amount] = min(take, notTake);
    return dp[i][amount];
}

int coinChange(int* coins, int coinsSize, int amount) {
    memset(dp, -1, sizeof(dp));
    int res = solve(coinsSize - 1, coins, amount);
    return (res >= INT_MAX - 1) ? -1 : res;
}

