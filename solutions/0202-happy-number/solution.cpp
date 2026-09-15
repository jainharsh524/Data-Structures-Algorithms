class Solution {
public:
    int digsum(int n){
        int sum = 0;
        while(n){
            int rem = n%10;
            n = n/10;
            sum += rem * rem;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            int sum = digsum(n);
            if(sum == 1) return true;
            else {
                if(st.find(sum) != st.end()) return false;
                else st.insert(sum);
            }
            n = sum;
        }
        return false;
    }
};
