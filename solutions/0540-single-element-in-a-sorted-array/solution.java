class Solution {
    static int binarySearching(int[] arr, int target){
        int high = arr.length-1;
        int low = 0;
        while(high>=low){
            int mid = low+(high-low)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    public static int[] searchRange(int[] nums, int target) {
        int[] arr = new int[2];
        int currIndex = binarySearching(nums, target);
        if(currIndex==-1){
            arr[0] = -1;
            arr[1] = -1;
        }
        else {
            int first = currIndex, last = currIndex;
            if(first==0) arr[0] = first;
            else {
                if (nums[first - 1] == nums[currIndex]) arr[0] = first - 1;
                else arr[0] = first;
            }
            if(last== nums.length-1) arr[1] = last;
            else {
                if (nums[last + 1] == nums[currIndex]) arr[1] = last+1;
                else arr[1] = last;
            }
        }
        return arr;
    }
    public int singleNonDuplicate(int[] nums) {
        int low = 0;
        int high = nums.length-1;
        while(high>=low){
            int mid = low+(high-low)/2;
            int[] positionsArray = searchRange(nums, nums[mid]);
            if(positionsArray[0]==positionsArray[1]){
                return nums[mid];
            }
            else{
                if(positionsArray[0]%2==1) high = mid-1;
                else if((nums.length-positionsArray[1]-1)%2==1) low = mid+1;
            }
        }
        return -1;
    }
}
