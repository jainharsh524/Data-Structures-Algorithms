#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

bool subsetSum(int i, int n, int arr[n], int targetSum , int dp[][1001]){
    if(targetSum==0) return true;
    if(i==0&&targetSum==arr[0]) return true;

    if (dp[i][targetSum] != -1) return dp[i][targetSum];
    bool took = false;
    if(targetSum>arr[i]){
        took = subsetSum(i-1, n, arr, targetSum-arr[i], dp);
    }
    bool untook = subsetSum(i-1, n, arr, targetSum, dp);
    dp[i][targetSum] = took || untook;
    return dp[i][targetSum];
}
int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 9;

    int dp[100][1001];
    memset(dp, -1, sizeof(dp));

    if (subsetSum(n - 1,n, arr, targetSum, dp)) {
        printf("Subset with sum %d exists.\n", targetSum);
    } else {
        printf("Subset with sum %d does not exist.\n", targetSum);
    }

    return 0;
}
