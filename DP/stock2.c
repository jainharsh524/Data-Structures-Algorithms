#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int dp[10001][2];

int profit(int index, bool buy, int arr[], int size){
    if(index == size) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    if(buy){
        dp[index][buy] = max(profit(index + 1, false, arr, size) - arr[index],profit(index + 1, true, arr, size));
    } 
    else {
        dp[index][buy] = max(profit(index + 1, true, arr, size) + arr[index],profit(index + 1, false, arr, size));
    }
    return dp[index][buy];
}

int main() {
    int arr[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Initialize dp array
    for(int i = 0; i <= size; i++){
        dp[i][0] = dp[i][1] = -1;
    }

    int result = profit(0, true, arr, size);
    printf("Maximum Profit: %d\n", result);
    return 0;
}
