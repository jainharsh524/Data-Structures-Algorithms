#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int minCal(int a, int b){
    return (a<b) ? a: b; // if we have to use return statements in the ternary operator then use it outside.
}

int jumpCost(int currIndex, int n, int arr[n], int dp[n+1]){
    if(currIndex ==0){
        dp[0] = 0;
        return 0;
    }
    else if(currIndex==1){
        dp[1] = abs(arr[1]-arr[0]);
        return dp[1];
    }
    else if (dp[currIndex] != -1){
        return dp[currIndex];
    }
    int left = jumpCost(currIndex-1, n, arr, dp)+ abs(arr[currIndex]-arr[currIndex-1]);
    int right = INT_MAX;
    right = jumpCost(currIndex-2, n, arr, dp)+ abs(arr[currIndex]-arr[currIndex-2]);
    dp[currIndex] = minCal(left, right);
    return dp[currIndex];
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    int result = jumpCost(n - 1, n, arr, dp);
    printf("%d\n", result);
    return 0;
}