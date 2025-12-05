#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int minCal(int a, int b){
    return (a<b) ? a: b; // if we have to use return statements in the ternary operator then use it outside.
}

//if we start from 0,0 we use right and down steps but as you can see in this que we are going from n-1, m-1
//to 0,0 so we used left and up.
int uniquePaths(int i, int j, int n, int m, int arr[n][m], int dp[n][m]){
    if(i==0&&j==0){
        return 1;
    }
    else if(i<0||j<0){
        return 0;
    }
    else if(arr[i][j]==-1){
        return 0;
    }
    else if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int left = uniquePaths(i, j-1, n, m, arr, dp);
    int up = uniquePaths(i-1, j, n, m, arr, dp);
    dp[i][j] = left+up;
    return dp[i][j];
}

int minCost(int i, int j, int n, int m, int arr[n][m], int dp[n][m]){
    if (i < 0 || j < 0) return 1e9; // large value to simulate infinity
    if (arr[i][j] == -1) return 1e9; // obstacle
    if (i == 0 && j == 0) return arr[0][0]; // base case: starting point

    if (dp[i][j] != -1) return dp[i][j];
    int left = arr[i][j]+minCost(i, j-1, n, m, arr, dp);
    int up = arr[i][j]+minCost(i-1, j, n, m, arr, dp);
    dp[i][j] = minCal(left, up);
    return dp[i][j];
}
int main(){
    int n;
    scanf("%d", &n);
    int m;
    scanf("%d", &m);
    int arr[n][m];
    for (int i = 0; i < n; i++){
        for(int j = 0;j<m;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int dp[n][m];
    for (int i = 0; i < n; i++){
        for(int j = 0;j<m;j++){
            dp[i][j] = -1;
        }
    }
    int cost = minCost(n-1, m-1, n, m, arr, dp);
    for (int i = 0; i < n; i++){
        for(int j = 0;j<m;j++){
            dp[i][j] = -1;
        }
    }
    int paths = uniquePaths(n-1, m-1, n, m, arr, dp);
    printf("%d\n", cost);
    printf("%d", paths);
    return 0;
}