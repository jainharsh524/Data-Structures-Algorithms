package Recursion;

public class arrayUsingRecursion {
    //1. Check whether array is sorted or not.
    public static boolean sorted(int[] arr){
        return helper(arr, 2);
    }
    private static boolean helper(int[] arr, int currIndex){
        if(currIndex== arr.length) return true;
        else {
            if (arr[currIndex] < arr[currIndex - 1]) return false;
            else return helper(arr, currIndex + 1);
        }
    }
    public static void main(String[] args) {
        System.out.println(sorted(new int[]{1,2,3,2,5}));
    }
}
