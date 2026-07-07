class Solution {
public:
    long long sumAndMultiply(int n) {
        int digsum = 0;
        long long val = 0;
        int place = 0;
        while(n>0){
            int dig = n%10;
            if(dig!=0){
                val = val+dig*pow(10, place);
                place++;
            }
            digsum += dig;
            n = n/10;
        }
        return val*digsum;
    }
};
