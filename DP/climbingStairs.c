#include <stdio.h>
#include <stdlib.h>

int waysToClimb(int n, int dp[n+1]){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int a = waysToClimb(n-1, dp);
    int b = waysToClimb(n-2, dp);
    dp[n] = a+b;
    return dp[n];
}

int main(){
    int n;
    scanf("%d", &n);
    int dp[n+1];
    for(int i = 0;i<n+1;i++){
        dp[i] = -1;
    }
    int ways = waysToClimb(n, dp);
    printf("%d", ways);
}