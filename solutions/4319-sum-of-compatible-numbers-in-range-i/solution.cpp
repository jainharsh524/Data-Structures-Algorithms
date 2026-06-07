class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int i= 0;
        int sum = 0;
        while(i<=(n+k)){
            if(abs(n-i)<=k&&((n&i)==0)) sum+=i;
            i++;
        }
        return sum;
    }
};
