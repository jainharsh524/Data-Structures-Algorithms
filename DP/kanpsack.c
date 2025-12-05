#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Memoization table (initialized with -1)
int dp[101][1001];

int knapsack(int i, int wt[], int val[], int W) {
    if (i == 0) {
        if (wt[0] <= W) return val[0];
        else return 0;
    }

    if (dp[i][W] != -1) return dp[i][W];

    // Not taking the current item
    int notTake = knapsack(i - 1, wt, val, W);

    // Taking the current item (if it fits)
    int take = 0;
    if (wt[i] <= W) {
        take = val[i] + knapsack(i - 1, wt, val, W - wt[i]);
    }

    dp[i][W] = max(take, notTake);
    return dp[i][W];
}

int main() {
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int n = sizeof(wt) / sizeof(wt[0]);
    int W = 7;

    // Initialize DP table with -1
    memset(dp, -1, sizeof(dp));

    int maxProfit = knapsack(n - 1, wt, val, W);
    printf("Maximum profit = %d\n", maxProfit);

    return 0;
}
