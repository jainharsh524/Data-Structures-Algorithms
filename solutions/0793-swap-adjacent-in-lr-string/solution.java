class Solution {
    public static boolean canTransform(String start, String result) {
        int len = start.length();
        int curr = 0;
        int curr1 = 0;
        int countL = 0,countR = 0,countX = 0;
        int countL1 = 0,countR1 = 0,countX1 = 0;
        for (int i = 0; i < start.length(); i++) {
            if(start.charAt(i)=='L')countL++;
            else if(start.charAt(i)=='R')countR++;
            else if(start.charAt(i)=='X')countX++;
        }
        for (int i = 0; i < start.length(); i++) {
            if(result.charAt(i)=='L')countL1++;
            else if(result.charAt(i)=='R')countR1++;
            else if(result.charAt(i)=='X')countX1++;
        }
        if(countL==countL1&&countR==countR1&&countX==countX1) {
            if (len == 1) return start.equals(result);
            else {
                while (curr < len && curr1 < len) {
                    if (start.charAt(curr) == 'X' || result.charAt(curr1) == 'X') {
                        if (start.charAt(curr) == 'X') curr++;
                        if (result.charAt(curr1) == 'X') curr1++;
                    } else {
                        if (start.charAt(curr) == result.charAt(curr1) && start.charAt(curr) == 'L') {
                            if (curr >= curr1) {
                                curr1++;
                                curr++;
                            } else return false;
                        } else if (start.charAt(curr) == result.charAt(curr1) && start.charAt(curr) == 'R') {
                            if (curr <= curr1) {
                                curr1++;
                                curr++;
                            } else return false;
                        } else if (start.charAt(curr) != result.charAt(curr1)) {
                            return false;
                        }
                    }
                }
            }
            return curr == start.length() || curr1 == result.length();
        }
        else return false;
    }
}
