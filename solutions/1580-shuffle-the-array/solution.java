class Solution {
    public static int[] shuffle(int[] nums, int n) {
        int[] nums1 = new int[2*n];
        for(int i=0;i< n;i++){
            nums1[2*i] = nums[i];
        }
        for(int j = 0; j < n; j++){
            nums1[(2*j)+1] = nums[j+n];
        }
        return nums1;
    }
}
