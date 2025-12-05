#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int minCal(int a, int b){
    return (a < b) ? a : b;
}

int minCost(int i, int j, int** arr, int** dp){
    if (i < 0 || j < 0 || j > i) return 1e9;
    if (i == 0 && j == 0) return arr[0][0];

    if (dp[i][j] != -1) return dp[i][j];

    int left = arr[i][j] + minCost(i - 1, j - 1, arr, dp);
    int up   = arr[i][j] + minCost(i - 1, j, arr, dp);

    dp[i][j] = minCal(left, up);
    return dp[i][j];
}

int main(){
    int n;
    scanf("%d", &n);
    
    int** arr = (int**)malloc(n * sizeof(int*));
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        arr[i] = (int*)malloc((i + 1) * sizeof(int));
        dp[i] = (int*)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++){
            scanf("%d", &arr[i][j]);
            dp[i][j] = -1;
        }
    }

    int cost = minCost(n - 1, n - 1, arr, dp);
    printf("%d\n", cost);

    // Free memory
    for (int i = 0; i < n; i++){
        free(arr[i]);
        free(dp[i]);
    }
    free(arr);
    free(dp);

    return 0;
}
