class Solution {
    public static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public int[] findErrorNums(int[] nums) {
        int[] arr = new int[2];
        int i =0;
        while(i<nums.length) {
            if(nums[i]-1<nums.length&&nums[i]-1!=i&&nums[i]!=nums[nums[i]-1]){
                swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        for (int j = 0; j < nums.length; j++) {
            if(nums[j]-1!=j){
                arr[0] = nums[j];
                arr[1] = j+1;
            }
        }
        return arr;
    }
}
