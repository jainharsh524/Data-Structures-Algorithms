class Solution {
    public static String mergeAlternately(String word1, String word2) {
        String mergedString = "";
        int i =0;
        while(i<word1.length()&&i<word2.length()){
            mergedString = mergedString+word1.charAt(i)+word2.charAt(i);
            i++;
        }
        if(word1.length()<word2.length()){
            while(i<word2.length()){
                mergedString = mergedString+word2.charAt(i);
                i++;
            }
        }
        else if (word1.length() > word2.length()) {
            while(i<word1.length()){
                mergedString = mergedString+word1.charAt(i);
                i++;
            }
        }
        return mergedString;
    }
}
