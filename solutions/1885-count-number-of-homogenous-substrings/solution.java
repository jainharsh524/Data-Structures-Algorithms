class Solution {
    public static int countHomogenous(String s) {
        char curr = s.charAt(0);
        int homo = 0;
        long countSubString = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)==curr){
                homo++;
            }
            else {
                curr = s.charAt(i);
                homo=1;
            }
            countSubString = countSubString+homo;
        }
        return (int)(countSubString%(Math.pow(10,9)+7));
    }
}
