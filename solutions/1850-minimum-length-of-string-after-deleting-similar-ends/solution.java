class Solution {
    public static int minimumLength(String s) {
        int ptr1 = 0;
        int ptr2 = s.length()-1;
        if(s.length()==0) return 0;
        else if(s.length()==1) return 1;
        else {
            char start = s.charAt(ptr1);
            StringBuilder sb = new StringBuilder(s);
            if (s.charAt(0) == s.charAt(s.length() - 1)) {
                while (ptr2 >= 0 && sb.charAt(ptr2) == start) {
                    sb = sb.deleteCharAt(ptr2);
                    ptr2--;
                }
                while (ptr1 < ptr2 && sb.charAt(ptr1) == start) {
                    sb = sb.deleteCharAt(ptr1);
                }
                s = sb.toString();
                return minimumLength(s);
            } else return s.length();
        }
    }
}
