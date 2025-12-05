#include <stdio.h>
#include <limits.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int dp[101][10001];  // dp[i][W] = min coins using first i+1 coins to make sum W

int minCoins(int i, int val[], int W) {
    if (W == 0) return 0;
    if (i < 0) return INT_MAX - 1;

    if (dp[i][W] != -1) return dp[i][W];

    int notTake = minCoins(i - 1, val, W);
    int take = INT_MAX - 1;
    if (val[i] <= W) {
        take = 1 + minCoins(i, val, W - val[i]);  // Can take again (unbounded)
    }

    dp[i][W] = min(take, notTake);
    return dp[i][W];
}

int main() {
    int val[] = {1, 2, 3};
    int n = sizeof(val) / sizeof(val[0]);
    int W = 5;

    memset(dp, -1, sizeof(dp));

    int result = minCoins(n - 1, val, W);
    if (result == INT_MAX - 1)
        printf("Not possible to make sum %d\n", W);
    else
        printf("Minimum coins to make sum %d = %d\n", W, result);

    return 0;
}
