class Solution {
    public static int sumOfDigits(int n){
        int sum = 0;
        while(n>0){
            int rem = n%10;
            sum+=rem;
            n=n/10;
        }
        return sum;
    }
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if(sumOfDigits(nums[i])==i) return i;
        }
        return -1;
    }
}
