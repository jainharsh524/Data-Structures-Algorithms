#include <stdio.h>
#include <string.h>

int dp[1001][1001];  // Memoization table

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestCommonSubstring(int i, int j, char* str1, char* str2, int* maxi) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    longestCommonSubstring(i - 1, j, str1, str2, maxi);
    longestCommonSubstring(i, j - 1, str1, str2, maxi);

    if (str1[i] == str2[j]) {
        dp[i][j] = 1 + longestCommonSubstring(i - 1, j - 1, str1, str2, maxi);
        *maxi = max(*maxi, dp[i][j]);
        return dp[i][j];
    } else {
        return dp[i][j] = 0;
    }
}

int main() {
    char str1[] = "abcde";
    char str2[] = "abfce";
    int n = strlen(str1);
    int m = strlen(str2);

    // Initialize dp array with -1
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    int maxi = 0;
    longestCommonSubstring(n - 1, m - 1, str1, str2, &maxi);

    printf("Length of Longest Common Substring: %d\n", maxi);
    return 0;
}
