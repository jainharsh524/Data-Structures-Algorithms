class Solution {
public:
    bool checkGoodInteger(int n) {
        int sqsum = 0;
        int digsum = 0;
        while(n>0){
            int rem = n%10;
            n = n/10;
            sqsum = sqsum+rem*rem;
            digsum +=rem;
        }
        return (sqsum-digsum>=50);
    }
};
