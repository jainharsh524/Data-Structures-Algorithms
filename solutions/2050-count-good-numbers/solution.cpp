class Solution {
public:
    const int MOD = 1e9+7;
    long long power(long long m, long long n){
        long long res = 1;
        while(n){
            if(n % 2 == 0){
                m = (m * m) % MOD;
                n /= 2;
            }
            else{
                res = (res * m) % MOD;
                n--;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenpow = (n + 1) / 2;
        long long primepow = n / 2;
        long long val1 = power(5, evenpow);
        long long val2 = power(4, primepow);
        return (val1 * val2) % MOD;
    }
};
