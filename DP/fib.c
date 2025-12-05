#include <stdio.h>
#include <stdlib.h>

int fib(int n, int dp[n+1]){
    if (n == 0 || n == 1)
        // dp[0] = 0;
        // dp[1] = 1;
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n-1, dp)+fib(n-2, dp);
    return dp[n];
}

int main(){
    int n;
    scanf("%d", &n);
    int dp[n+1];
    for (int i = 0; i <= n; i++)
        dp[i] = -1;
    int val = fib(n, dp);
    printf("%d", val);
    return 0;
}