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
    int n = strlen(str1);
    char str2[n + 1]; // +1 for null-terminator
    for (int i = 0; i < n; i++) {
        str2[i] = str1[n - i - 1];
    }
    str2[n] = '\0';
    // Initialize dp array
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;

    int result = longestCommonSubsequence(n - 1, n - 1, str1, str2);

    printf("Length of Longest Palindromic Subsequence: %d\n", result);
    return 0;
}