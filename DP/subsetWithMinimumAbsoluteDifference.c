#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int subsetSum(int i, int n, int arr[n], int targetSum , int dp[][1001]){
    if (targetSum == 0) return 1;
    if (i == 0) return arr[0] == targetSum;

    if (dp[i][targetSum] != -1) return dp[i][targetSum];

    int took = 0;
    if (targetSum >= arr[i]) {
        took = subsetSum(i - 1, n, arr, targetSum - arr[i], dp);
    }
    int untook = subsetSum(i - 1, n, arr, targetSum, dp);

    dp[i][targetSum] = took || untook;
    return dp[i][targetSum];
}


int minAbsDiff(int dp[][1001], int n, int sum){
    int min = INT_MAX;
    for (int s1 = 0; s1 <= sum / 2; s1++) {
        if (dp[n - 1][s1] == 1) {
            int s2 = sum - s1;
            int diff = abs(s2 - s1);
            if (diff < min) {
                min = diff;
            }
        }
    }
    return min;
}

int main() {
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int dp[n][1001];
    memset(dp, -1, sizeof(dp));

    // Fill the dp table with subset existence info
    for (int i = 0; i < 1001; i++) {
        subsetSum(n - 1, n, arr, i, dp);
    }
    int result = minAbsDiff(dp, n, sum);
    printf("Minimum subset sum difference = %d\n", result);
    return 0;
}

