class Solution {
    public static String convertToTitle(int columnNumber) {
        StringBuilder sb = new StringBuilder();
        while(columnNumber>0){
            char ch = (char)(columnNumber%26+64);
            if(ch=='@') {
                sb.append('Z'); columnNumber--;
            }
            else sb.append(ch);
            columnNumber = columnNumber/26;
        }
        return sb.reverse().toString();
    }
}
