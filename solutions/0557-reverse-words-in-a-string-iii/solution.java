class Solution {
    public static void swap(char[] arr, int index1, int index2){
        char temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
    public static String reverse(String s){
        char[] charArray = s.toCharArray();
        int i = 0, j = s.length()-1;
        while (i<j){
            swap(charArray, i, j);
            i++;j--;
        }
        return String.valueOf(charArray);
    }
    public static String reverseWords(String s) {
        String[] arr = s.split(" ");
        for (int i = 0; i < arr.length; i++) arr[i] = reverse(arr[i]);
        s = "";
        for (int i = 0; i < arr.length; i++) s = s + arr[i]+" ";
        return s.trim();
    }
}
