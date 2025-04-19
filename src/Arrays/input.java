package Arrays;
import java.util.*;
public class input {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[4];
        arr[0] = 2;
        arr[1] = sc.nextInt();
        arr[2] = 8;
        arr[3] = sc.nextInt();

        int[] arr1 = new int[4];
        // input using for loops
        //in array data structure length is an attribute of array class not a function.
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = sc.nextInt();
        }

        //Enhanced for loop
        for(int num : arr) { // for every element in array, print the element
            System.out.print(num + ", "); //  here num represents element of the array
        }

//        System.out.println(arr[5]); // index out of bound error

        String[] str = new String[4];
        for (int i = 0; i < str.length; i++) {
            str[i] = sc.next();
        }

        System.out.println(Arrays.toString(str));


    }
}
