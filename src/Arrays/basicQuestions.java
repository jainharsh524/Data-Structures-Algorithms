package Arrays;
import java.util.*;
public class basicQuestions {
    //1. swap the elements and reverse the array.
    static int[] reverseBySwapping(int[] arr){
        for(int i =0;i<arr.length/2;i++){
            int temp = arr[i];
            arr[i] = arr[arr.length-i-1];
            arr[arr.length-i-1] = temp;
        }
        return arr;
    }
    //2. max value in the array
    static int max(int[] arr){
        int maximum = arr[0];
        for(int i =0;i<arr.length;i++){
            if(arr[i]>maximum) maximum = arr[i];
        }
        return maximum;
    }
    public static void main(String[] args) {
        int[] arr = {12,1,4,15,6,7};
        arr = reverseBySwapping(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(max(arr));
    }

}
