class Solution {
    public static String sum(String[] word1){
        String sum = "";
        for (int i = 0; i < word1.length; i++) {
            sum+=word1[i];
        }
        return sum;
    }
    public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String s1 = sum(word1);
        String s2 = sum(word2);
        return s1.equals(s2);
    }
}
