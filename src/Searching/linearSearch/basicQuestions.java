package Searching.linearSearch;

public class basicQuestions {
    //1. search in particular range.
    static boolean rangeSearch(int[] arr, int startIndex, int endIndex, int target){
        if(arr.length==0){
            return false;
        }
        if(startIndex<0){
            for(int i = 0;i <= endIndex;i++){
                if(arr[i] == target){
                    return true;
                }
            }
        }
        if(endIndex>arr.length){
            for(int i = startIndex;i < arr.length;i++){
                if(arr[i] == target){
                    return true;
                }
            }
        }
        for(int i = startIndex;i <= endIndex;i++){
            if(arr[i] == target){
                return true;
            }
        }
        return false;
    }

    //2.find minimum element's index.
    static int minIndex(int[] arr){
        int min = arr[0];
        int index = 0;
        for(int i =0;i<arr.length;i++){
            if(min<arr[i]){
                min = arr[i];
                index = i;
            }
        }
        return index;
    }

    //3. search in 2D arrays
    static String search2D(int [][] arr, int target){
        for(int i =0;i<arr.length;i++){
            for(int j =0;j<arr[i].length;j++){
                if(arr[i][j]==target) return "Target found at "+(i+1)+"th row and "+(j+1)+"th column.";
            }
        }
        return "not found";
    }
    //4. https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
    //find numbers with even number of digits
    static int numberOfDigits(int num){
        return (int)Math.log10(num)+1;
    }
    public static int findNumbers(int[] num) {
        int count =0;
        for(int i =0;i<num.length;i++){
            if(numberOfDigits(num[i])%2==0) count++;
        }
        return count;
    }

    //5.https://leetcode.com/problems/richest-customer-wealth/description/
    static int sum(int[] arr){
        int sum =0;
        for(int i =0;i< arr.length;i++){
            sum+=arr[i];
        }
        return sum;
    }
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        for(int i =0;i<accounts.length;i++){
            int wealth = sum(accounts[i]);
            if(wealth>maxWealth){
                maxWealth = wealth;
            }
        }
        return maxWealth;
    }
    public static void main(String[] args) {
        int[] arr = {12,2,345678,4,52,63};
        int[][] arr2D = {{1,2,3},
                          {4,5,6},
                           {7,8,9}};
        System.out.println(rangeSearch(arr, 0,5,6));
        System.out.println(minIndex(arr));
        System.out.println(search2D(arr2D, 7));
        System.out.println(findNumbers(arr));
    }
}
