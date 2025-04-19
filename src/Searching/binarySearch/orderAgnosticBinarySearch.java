package Searching.binarySearch;

public class orderAgnosticBinarySearch {
    //Order Agnostic binary search means we don't know that in which order the array is sorted.
    static int orderAgnosticBinarySearching(int[] arr, int target){
        int high = arr.length-1;
        int low = 0;
        //Ascending Order sorted array
        if(arr[low]<arr[high]){
            while(high>=low){
                int mid = low+(high-low)/2;
                if(arr[mid]==target) return mid;
                else if(arr[mid]>target) high = mid-1;
                else low = mid+1;
            }
        }
        //Descending Order sorted array
        else{
            while(high>=low){
                int mid = low+(high-low)/2;
                if(arr[mid]==target) return mid;
                else if(arr[mid]<target) high = mid-1;
                else low = mid+1;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] arr = {6,5,4,3,2,1};
        System.out.println(orderAgnosticBinarySearching(arr, 5));
    }
}
