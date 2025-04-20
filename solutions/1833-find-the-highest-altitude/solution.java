class Solution {
    public int[] runningSum(int[] nums) {
        for(int i =1;i< nums.length;i++){
            nums[i] = nums[i]+nums[i-1];
        }
        return nums;
    }
    public static int max(int[] arr){
        int max =arr[0];
        for(int i =0;i<arr.length;i++){
            if(max<arr[i]) max = arr[i];
        }
        return max;
    }
    public int largestAltitude(int[] gain) {
        gain = runningSum(gain);
        if(max(gain)>0) return max(gain);
        else return 0;
    }
}
