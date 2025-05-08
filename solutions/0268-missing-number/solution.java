class Solution {
    public static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public static int missingNumber(int[] nums) {
        int i =0;
        while(i<nums.length) {
            if(nums[i]<nums.length&&nums[i]!=i){
                swap(nums, i, nums[i]);
            }
            else i++;
        }
        for (int j = 0; j < nums.length; j++) {
            if(nums[j]!=j) return j;
        }
        return nums.length;
    }
}
