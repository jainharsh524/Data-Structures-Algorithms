class Solution {
    public static int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int top = 0, bottom = n-1;
        int left = 0, right = n-1;
        int entry = 1;
        while (top <= bottom && left <= right) {
            // Top row
            for (int i = left; i <= right; i++) {
                matrix[top][i] = entry;
                entry++;
            }
            top++;
            // Right column
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = entry;
                entry++;
            }
            right--;
            if (top <= bottom) {
                // Bottom row
                for (int i = right; i >= left; i--) {
                    matrix[bottom][i] = entry;
                    entry++;
                }
                bottom--;
            }
            if (left <= right) {
                // Left column
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = entry;
                    entry++;
                }
                left++;
            }
        }
        return matrix;
    }
}
