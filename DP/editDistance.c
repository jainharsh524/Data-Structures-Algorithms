#include <stdio.h>
#include <string.h>

int dp[501][501];  // Adjust size if needed

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int solve(int i, int j, char* word1, char* word2) {
    if (i < 0) return j + 1;  // Insert all remaining characters of word2
    if (j < 0) return i + 1;  // Delete all remaining characters of word1

    if (dp[i][j] != -1) return dp[i][j];

    if (word1[i] == word2[j])
        return dp[i][j] = solve(i - 1, j - 1, word1, word2);

    int insertOp = solve(i, j - 1, word1, word2);
    int deleteOp = solve(i - 1, j, word1, word2);
    int replaceOp = solve(i - 1, j - 1, word1, word2);

    return dp[i][j] = 1 + min(insertOp, deleteOp, replaceOp);
}

int editDistance(char* word1, char* word2) {
    int n = strlen(word1);
    int m = strlen(word2);

    // Initialize dp array
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = -1;

    return solve(n - 1, m - 1, word1, word2);
}
int main() {
    char word1[] = "horse";
    char word2[] = "ros";
    printf("Edit Distance: %d\n", editDistance(word1, word2));
    return 0;
}
