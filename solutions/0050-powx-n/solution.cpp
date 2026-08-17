class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        double res = 1;
        if(N < 0) N = -N;
        while(N){
            if(N % 2 == 1){
                res *= x;
                N--;
            }
            else{
                x *= x;
                N /= 2;
            }
        }
        return n < 0 ? 1 / res : res;
    }
};
