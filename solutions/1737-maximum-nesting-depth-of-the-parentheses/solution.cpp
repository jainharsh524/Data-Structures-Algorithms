class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int bal = 0;
        for(char ch: s){
            if(ch=='(') bal++;
            else if(ch==')') bal--;
            maxi = max(maxi, bal);
        }
        return maxi;
    }
};
