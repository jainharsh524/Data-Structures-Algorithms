class Solution {
    public static void swap(int[] nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    public static int firstMissingPositive(int[] nums) {
        for(int i =  0; i < nums.length; i++){
        while(nums[i] > 0 && nums[i] - 1 < nums.length && nums[i] - 1 != i && nums[nums[i]-1] != nums[i]){
           swap(nums, i, nums[i] - 1); 
        }  
      }
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]-1!=i){
                return i+1;
            }
        }
        return nums.length+1;
    }
}
