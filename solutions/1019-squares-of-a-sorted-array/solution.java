class Solution {
    public static int[] sortedSquares(int[] nums) {
        int[] squaredNums = new int[nums.length];
        int i =0;
        int j = nums.length-1;
        int index = j;
        while (i<=j){
            if(Math.abs(nums[i])>Math.abs(nums[j])) {
                squaredNums[index] = nums[i]*nums[i];
                index--;i++;
            }
            else {
                squaredNums[index] = nums[j]*nums[j];
                index--;j--;
            }
        }
        return squaredNums;
    }
}
