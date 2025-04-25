package Searching.binarySearch;

public class floor {
    public static int floor(int[] arr, int target){
        if(target<arr[0]) return -1;
        else {
            int low = 0;
            int high = arr.length - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] == target) return arr[mid];
                else if (arr[mid] > target) high = mid - 1;
                else low = mid + 1;
            }
            return arr[high];
        }
    }
    public static void main(String[] args) {
        int[] arr = {2,3,5,8,14,15,18};
        System.out.println(floor(arr, 17));
    }
}
