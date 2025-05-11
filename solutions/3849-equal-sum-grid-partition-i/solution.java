class Solution {
    public boolean canPartitionGrid(int[][] grid) {
       int m = grid.length;
        int n = grid[0].length;

        // Compute total sum of all elements
        long totalSum = 0;
        long[] rowSum = new long[m];
        long[] colSum = new long[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                totalSum += grid[i][j];
            }
        }
        long prefixRowSum = 0;
        for (int i = 0; i < m - 1; i++) {
            prefixRowSum += rowSum[i];
            if (prefixRowSum * 2 == totalSum) return true;
        }
        long prefixColSum = 0;
        for (int j = 0; j < n - 1; j++) {
            prefixColSum += colSum[j];
            if (prefixColSum * 2 == totalSum) return true;
        }

        return false;
    }
}
