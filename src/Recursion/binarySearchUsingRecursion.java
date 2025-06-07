package Recursion;

public class binarySearchUsingRecursion{
    public static int BS(int[] arr, int target, int low, int high){
        int mid = low + (high-low)/2;
        if(low>=high&&mid!=target) return -1;
        else {
            if (target == arr[mid]) return mid;
            else if (target > arr[mid]) return BS(arr, target, mid + 1, high);
            else return BS(arr, target, low, mid - 1);
        }
    }
    public static void main(String[] args) {
        System.out.println(BS(new int[]{1,2,3,4,5,6}, -4, 0, 6));
    }
}
