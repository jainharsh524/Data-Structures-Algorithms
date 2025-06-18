class Solution {
    public boolean hasAlternatingBits(int num) {
        int prev = -1;
        while (num>0){
            int curr = num&1;
            num = num>>1;
            if(prev==curr) return false;
            else prev = curr;
        } 
        return true;
    }
}
