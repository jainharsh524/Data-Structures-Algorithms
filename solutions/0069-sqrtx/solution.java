class Solution {
    public static int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        int low = 0;
        int high = x;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mid*mid==x) return mid;
            else if(((long) mid *mid)<(long)x) low = mid+1;
            else if(((long)mid*mid)>(long)x) high = mid-1;
        }
        return high;
    }
}
