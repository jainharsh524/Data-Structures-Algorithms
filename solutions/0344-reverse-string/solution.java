class Solution {
    public static void reverseHelper(char[] s, int i, int j){
        if(i<j) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            reverseHelper(s, i + 1, j - 1);
        }
    }
    public static void reverseString(char[] s) {
        reverseHelper(s,0,s.length-1);
    }
}
