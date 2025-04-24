class Solution {
    static int binarySearching(int[] arr, int target){
        //for array sorted in ascending order only.
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
            while (first > 0) {
                if (nums[first - 1] == nums[currIndex]){
                    first--;
                    arr[0] = first;
                }
                else {
                    arr[0] = first;
                    break;
                }
            }
            if(last== nums.length-1){
                arr[1] = last;
            }
            else {
                while (last < nums.length - 1) {
                    if (nums[last + 1] == nums[currIndex]) {
                        last++;
                        arr[1] = last;
                    } else {
                        arr[1] = last;
                        break;
                    }
                }
            }
        }
        return arr;
    }
}
