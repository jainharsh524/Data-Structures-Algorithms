class Solution {
    public static int[] plusOne(int[] digits) {
        int carry = 0;
        List<Integer> result = new ArrayList<>();
        int a = digits[digits.length-1];
        a = a+1;
        result.add(0,a % 10);
        carry = a / 10;
        
        for(int i =digits.length-2;i>=0;i--){
            int newValue = digits[i]+carry;
            result.add(0,newValue%10);
            carry = newValue/10;
        }
        if(carry!=0){
            result.add(0,carry);
        }
        int[] res = new int[result.size()];
        System.out.println(result);
        for (int i = 0; i < result.size(); i++) {
            res[i] = result.get(i);
        }
        return res;
    }
}
