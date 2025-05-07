package Sorting.bubbleSort;

import java.util.Arrays;

public class bubbleSort {
    public static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public static int[] sort(int[] arr){
        boolean swap = false;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 1; j < arr.length-i; j++) {
                if(arr[j]<arr[j-1]) swap(arr, j, j-1);swap = true;
            }
            if(!swap) break;
        }
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = {2,3,1,5,4};
        System.out.println(Arrays.toString(sort(arr)));
    }
}
