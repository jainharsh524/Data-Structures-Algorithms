class Solution {
    public int majorityElement(int[] nums) {
        int votes = 0;
        int majorElement = -1;
        for (int i = 0; i < nums.length; i++) {
            if(votes==0) majorElement = nums[i];
            if(nums[i]==majorElement){
                votes++;
            }
            else votes--;
        }
        return majorElement;
    }
}
