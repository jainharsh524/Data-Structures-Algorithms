package Searching.binarySearch;

public class ceiling {
//    public static int ceil(int[] arr, int target){
//        int low = 0;
//        int high = arr.length-1;
//        while(low<=high){
//            int mid = low+(high-low)/2;
//            if(arr[mid]==target||(arr[mid]>target&&arr[mid-1]<target)) return arr[mid];
//            else if(arr[mid]>target) high = mid-1;
//            else low = mid+1;
//        }
//        return -1;
//    }
    //above code gives error for index 0;

    //Algorithm:
    //Check if the target is larger than the last element:
        //If target > arr[n - 1], return -1 → ceil doesn't exist.
    //Initialize Binary Search:
        //low = 0, high = n - 1
    //Run Binary Search Loop while low ≤ high:
        //Calculate mid = low + (high - low) / 2
        //If arr[mid] == target, return arr[mid] (it's the ceil)
        //If arr[mid] > target, search left side → high = mid - 1
        //If arr[mid] < target, search right side → low = mid + 1
    //After the loop, low points to the smallest number ≥ target:
        //Return arr[low] as the ceil
    public static int ceil(int[] arr, int target){
        if(target>arr[arr.length-1]) return -1;
        else {
            int low = 0;
            int high = arr.length - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) return arr[mid];
                else if (arr[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return arr[low];
        }
    }
    public static void main(String[] args) {
        int[] arr = {2,3,5,8,14,15,18};
        System.out.println(ceil(arr, 17));
    }
}
