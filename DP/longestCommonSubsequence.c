#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dp[1001][1001];  // Assuming max string length is 1000

int longestCommonSubsequence(int i, int j, char* str1, char* str2) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (str1[i] == str2[j]) return dp[i][j] = 1 + longestCommonSubsequence(i - 1, j - 1, str1, str2);
    return dp[i][j] = max(longestCommonSubsequence(i - 1, j, str1, str2), longestCommonSubsequence(i, j - 1, str1, str2));
}

int main(){
    char str1[] = "abcde";
    char str2[] = "ace";
    int n = strlen(str1);
    int m = strlen(str2);

    // Initialize dp array
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    int result = longestCommonSubsequence(n - 1, m - 1, str1, str2);

    printf("Length of LCS: %d\n", result);
    return 0;
}