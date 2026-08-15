class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool isPositive = (dividend > 0) == (divisor > 0);
        unsigned int a = labs(dividend);
        unsigned int b = labs(divisor);
        unsigned int ans = 0;
        while (b <= a) {
            int i = 0;
            while (i < 31 && a > (b << (i + 1))) i++;
            ans += 1u << i;
            a -= b << i;
        }
        if (ans == (1u << 31)) {
            return isPositive ? INT_MAX : INT_MIN;
        }
        return isPositive ? (int)ans : -(int)ans;
    }
};
