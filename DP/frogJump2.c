#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//unsolved

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    int result = canJump(n - 1, n, arr, dp);
    printf("%d\n", result);
    return 0;
}