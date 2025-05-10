class Solution {
    public static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public static int[] sortArrayByParity(int[] nums) {
        int i =0, j = nums.length-1;
        while(i< j){
            if(nums[i]%2!=0&&nums[j]%2==0){
                swap(nums, i, j);
                i++;j--;
            }
            else if(nums[i]%2==0){
                i++;
            } else if (nums[j]%2!=0) {
                j--;
            }
        }
        return nums;
    }
}
