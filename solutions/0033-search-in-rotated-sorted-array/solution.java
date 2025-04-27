class Solution {
    public static int pivotIndex(int[] nums){
        int low = 0;
        int high = nums.length-1;
        while(high>=low){
            int mid = low+(high-low)/2;
            if(mid<high && nums[mid]>nums[mid+1]) return mid;
            if(mid>low && nums[mid]<nums[mid-1]) return mid-1;
            if(nums[mid]<=nums[low]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    public static int binarySearch(int[] nums, int target, int low, int high){
        while(high>=low){
            int mid = low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    public static int search(int[] nums, int target) {
        int pivot = pivotIndex(nums);
        int index = binarySearch(nums, target, 0, pivot);
        if(index==-1){
            index = binarySearch(nums, target, pivot+1, nums.length-1);
        }
        return index;
    }
}
