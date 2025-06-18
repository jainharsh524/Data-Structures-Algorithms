class Solution {
    public static int hammingWeight(int num) {
        int count = 0;
        while (num>0){
            int end = num&1;
            if(end==1) count++;
            num = num>>1;
        }
        return count;
    }
    public static boolean isPrime(int num){
        if(num==1) return false;
        else if(num==2) return true;
        else {
            int i = 2;
            while(i<num){
                if(num%i==0) return false;
                else i++;
            }
        }
        return true;
    }
    public static int countPrimeSetBits(int left, int right) {
        int countPrime = 0;
        int curr = left;
        while(curr<=right){
            int setBits = hammingWeight(curr);
            if(isPrime(setBits)) countPrime++;
            curr++;
        }
        return countPrime;
    }
}
