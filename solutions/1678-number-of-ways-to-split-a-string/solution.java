class Solution {
    public static int numWays(String s) {
        int MOD = 1_000_000_007;
        int n = s.length();
        int totalOnes = 0;

        // Count total number of 1s
        for (char c : s.toCharArray()) {
            if (c == '1') totalOnes++;
        }

        // Case 1: All zeroes
        if (totalOnes == 0) {
            return (int) ((long)(n - 1) * (n - 2) / 2 % MOD);
        }

        // Case 2: Cannot divide into 3 equal parts
        if (totalOnes % 3 != 0) return 0;

        // Case 3: Exactly divisible
        int target = totalOnes / 3;
        int onesSeen = 0;
        long firstSplitWays = 0;
        long secondSplitWays = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == '1') onesSeen++;

            if (onesSeen == target) firstSplitWays++;
            else if (onesSeen == 2 * target) secondSplitWays++;
        }

        return (int) (firstSplitWays * secondSplitWays % MOD);
    }
}
