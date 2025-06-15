class Solution {
    public static String addBinary(String a, String b) {
        StringBuilder sum = new StringBuilder();
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        int val  = 0;
        while(i>=0&&j>=0){
            val  = 0;
            if(a.charAt(i)=='0'&&b.charAt(j)=='0'){
                val = carry;
                sum.append(val);i--;j--;
                carry = 0;
            }
            else if(a.charAt(i)=='1'&&b.charAt(j)=='0'){
                val = carry+1;
                if(val==2){
                    carry = 1;
                    val = 0;
                }
                else carry = 0;
                sum.append(val);i--;j--;
            }
            else if(a.charAt(i)=='0'&&b.charAt(j)=='1'){
                val = carry+1;
                if(val==2){
                    carry = 1;
                    val = 0;
                }
                else carry = 0;
                sum.append(val);i--;j--;
            }
            else {
                val = carry;
                sum.append(val);i--;j--;
                carry = 1;
            }
        }
        if(i>=0){
            while(i>=0){
                if(carry == 0){
                    sum.append(a.charAt(i));
                }
                else {
                    if(a.charAt(i)=='1'){
                        sum.append('0');
                        carry = 1;
                    }
                    else {
                        sum.append('1');
                        carry = 0;
                    }
                }
                i--;
            }
        }
        else if(j>=0){
            while(j>=0){
                if(carry == 0){
                    sum.append(b.charAt(j));
                }
                else {
                    if(b.charAt(j)=='1'){
                        sum.append('0');
                        carry = 1;
                    }
                    else {
                        sum.append('1');
                        carry = 0;
                    }
                }
                j--;
            }
        }
        if(carry!=0){
            sum.append(carry);
        }
        return sum.reverse().toString();
    }
}
