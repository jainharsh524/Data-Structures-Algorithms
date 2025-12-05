#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int maxCal(int a, int b){
    return (a>b) ? a: b; // if we have to use return statements in the ternary operator then use it outside.
}
int maxSum(int i, int n, int arr[n], int dp[n]){
    if(i==0){
        return arr[i];
    }
    if(i<0) return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int l = arr[i]+maxSum(i-2, n, arr, dp);
    int r = maxSum(i-1, n, arr, dp);
    dp[i] = maxCal(r, l);
    return dp[i];
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dp[n];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    
    int result = maxSum(n-1, n, arr, dp);
    printf("%d\n", result);
    return 0;
}