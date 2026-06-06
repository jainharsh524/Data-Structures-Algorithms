class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;

        p = p < 0 ? -p : p;
        double ans = 1.0;
        while (p > 0) {
            if (p % 2 == 1) {
                ans = ans * x;
                p--;
            } 
            else { 
                x = x * x;
                p /= 2;
            }
        }
        
        if (n < 0) {
            return (double)(1.0) / (double)(ans);
        }
        return ans;
    }
};
