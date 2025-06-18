class Solution {
    public int xorOperation(int n, int start) {
       n--;
        int val = start+(n)*2;
        if(n==0){
            return start;
        }
        else return val^xorOperation(n, start);
    }
}
