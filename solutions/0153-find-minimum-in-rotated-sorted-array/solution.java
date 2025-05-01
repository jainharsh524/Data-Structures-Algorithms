class Solution {
    public static int findPeak(int[] nums){
        int low = 0;
        int high = nums.length-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(mid<high&&nums[mid]>nums[mid+1]) return mid;
            else if(mid>low&&nums[mid-1]>nums[mid]) return mid-1;
            else if(nums[mid]>=nums[low]) low = mid+1;
            else if(nums[mid]<nums[low]) high = mid-1;
        }
        return low;
    }
    public static int findMin(int[] nums) {
        int peakIndex = findPeak(nums);
        return nums[(peakIndex+1)%nums.length];
    }
}
