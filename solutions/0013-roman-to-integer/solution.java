class Solution {
    public static int romanToInt(String s) {
        int value = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if(s.charAt(i)=='I') value++;
            else if(s.charAt(i)=='V'){
                if(i>0&&s.charAt(i-1)=='I') {
                    value = value+4;
                    i--;
                }
                else {
                    value = value+5;
                }
            }
            else if(s.charAt(i)=='X'){
                if(i>0&&s.charAt(i-1)=='I') {
                    value = value+9;
                    i--;
                }
                else {
                    value = value+10;
                }
            }
            else if(s.charAt(i)=='L'){
                if(i>0&&s.charAt(i-1)=='X') {
                    value = value+40;
                    i--;
                }
                else {
                    value = value+50;
                }
            }
            else if(s.charAt(i)=='C'){
                if(i>0&&s.charAt(i-1)=='X') {
                    value = value+90;
                    i--;
                }
                else {
                    value = value+100;
                }
            }
            else if(s.charAt(i)=='D'){
                if(i>0&&s.charAt(i-1)=='C') {
                    value = value+400;
                    i--;
                }
                else {
                    value = value+500;
                }
            }
            else if(s.charAt(i)=='M'){
                if(i>0&&s.charAt(i-1)=='C') {
                    value = value+900;
                    i--;
                }
                else {
                    value = value+1000;
                }
            }
        }
        return value;
    }
}
