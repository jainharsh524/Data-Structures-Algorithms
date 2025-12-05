#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dp[100001][2][3];  // index, canBuy, transactionsLeft

int solve(int index, int canBuy, int transactionsLeft, int* prices, int n) {
    if (index == n || transactionsLeft == 0) return 0;

    if (dp[index][canBuy][transactionsLeft] != -1)
        return dp[index][canBuy][transactionsLeft];

    if (canBuy) {
        // Option 1: Buy now
        int buy = -prices[index] + solve(index + 1, 0, transactionsLeft, prices, n);
        // Option 2: Skip buying
        int skip = solve(index + 1, 1, transactionsLeft, prices, n);
        return dp[index][canBuy][transactionsLeft] = max(buy, skip);
    } else {
        // Option 1: Sell now
        int sell = prices[index] + solve(index + 1, 1, transactionsLeft - 1, prices, n);
        // Option 2: Skip selling
        int skip = solve(index + 1, 0, transactionsLeft, prices, n);
        return dp[index][canBuy][transactionsLeft] = max(sell, skip);
    }
}

int maxProfit(int* prices, int pricesSize) {
    // Initialize memo table
    for (int i = 0; i <= pricesSize; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    return solve(0, 1, 2, prices, pricesSize);  // start at index 0, canBuy=1, 2 transactions
}
