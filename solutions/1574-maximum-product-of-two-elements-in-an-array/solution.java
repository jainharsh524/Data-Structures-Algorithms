class Solution {
    public int maxProduct(int[] nums) {
        Arrays.sort(nums);
        int last = nums.length-1;
        return (nums[last]-1)*(nums[last-1]-1);
    }
}
