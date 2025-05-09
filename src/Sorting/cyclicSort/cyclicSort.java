package Sorting.cyclicSort;

import java.util.Arrays;

public class cyclicSort {
    public static void swap(int[] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public static void sort(int[] arr){
        int i =0;
        while(i< arr.length) {
            if(arr[i]-1!=i){
                swap(arr, i, arr[i]-1);
            }
            else i++;
        }
    }
    public static void main(String[] args) {
        int[] arr = {2,3,1,4,5};
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
