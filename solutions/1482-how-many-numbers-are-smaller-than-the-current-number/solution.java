class Solution {
    static int findMax(int[] arr){
        int max = arr[0];
        for (int i =0;i<arr.length;i++){
            if(arr[i]>max) max = arr[i];
        }
        return max;
    }
    public static int[] smallerNumbersThanCurrent(int[] nums) {
        int[] frequencyBucket = new int[findMax(nums)+1];
        int[] res = new int[nums.length];
        for (int i =0; i < nums.length; i++) frequencyBucket[nums[i]]++;

        for (int i = 1 ; i < frequencyBucket.length; i++) frequencyBucket[i] += frequencyBucket[i-1];

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) res[i] = 0;
            else res[i] = frequencyBucket[nums[i] - 1];
        }
        return res;
    }
}
