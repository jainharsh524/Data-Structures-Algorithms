package Searching.binarySearch;

public class binarySearch {
    static int binarySearching(int[] arr, int target){
        //for array sorted in ascending order only.
        int high = arr.length-1;
        int low = 0;
        while(high>=low){
            //find the middle index
//            int mid = (high+low)/2;//might exceed the range of int by doing (start+end)
            int mid = low+(high-low)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    //Time Complexity: O(logN)
    //used for sorted arrays
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6};
        System.out.println(binarySearching(arr, 5));
    }
}
