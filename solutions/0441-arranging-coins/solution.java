class Solution {
    public static long seriesSum(int n){
        return (long)n*(n+1)/2;
    }
    public static int arrangeCoins(int n) {
        int low = 0;
        int high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long value = seriesSum(mid);
            if ((long)n == value) return mid;
            else if ((long)n < value) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
}
