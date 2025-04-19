class Solution {
    public static  int[] buildArray(int[] nums) {
        int[] num1 = new int[nums.length];
        for(int i =0;i<nums.length;i++){
            num1[i] = nums[nums[i]];
        }
        return num1;
    }
}
