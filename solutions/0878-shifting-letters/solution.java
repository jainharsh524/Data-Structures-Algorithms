class Solution {
    public static String shiftingLetters(String s, int[] shifts) {
        StringBuilder sb = new StringBuilder(s);
        long shift=0;
        for (int i = s.length()-1; i >=0 ; i--){
            sb.setCharAt(i, (char)((s.charAt(i) - 97 + (shift+shifts[i]) % 26) % 26 + 97));
            shift+=shifts[i];
        }
        return sb.toString();
    }
}
