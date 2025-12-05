#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

int subsetSum(int i, int n, int arr[n], int targetSum , int dp[][1001]){
    if(targetSum==0) return 1;
    if(i==0&&targetSum==arr[0]) return 1;

    if (dp[i][targetSum] != -1) return dp[i][targetSum];
    int took = -1;
    if(targetSum>arr[i]){
        took = subsetSum(i-1, n, arr, targetSum-arr[i], dp);
    }
    int untook = subsetSum(i-1, n, arr, targetSum, dp);
    dp[i][targetSum] = took + untook;
    return dp[i][targetSum];
}
int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for(int i =0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2==1){
        return false;
    }
    else{
        int dp[n][1001];
        memset(dp, -1, sizeof(dp));
        int targetSum = sum/2;
        int count  = subsetSum(n-1, n, arr, targetSum, dp);
    }

    
    return 0;
}
