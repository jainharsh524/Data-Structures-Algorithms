public class Solution {
    
    public int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(n, index, maxSum, mid)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }

    private boolean isValid(int n, int index, int maxSum, int peak) {
        long leftSum = calcSum(index, peak - 1);
        long rightSum = calcSum(n - index - 1, peak - 1);
        long total = leftSum + rightSum + peak;
        return total <= maxSum;
    }

    private long calcSum(int length, int peak) {
        if (peak >= length) {
            long full = (long)(peak + (peak - length + 1)) * length / 2;
            return full;
        } else {
            long decreasing = (long)(peak + 1) * peak / 2;
            long ones = (long)(length - peak);
            return decreasing + ones;
        }
    }
}

