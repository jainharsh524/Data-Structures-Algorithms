class Solution {
public:
    int count(string s, int index, vector<int>& dp){
        if(index>=s.size()) return 1;
        if(dp[index]!=-1) return dp[index];
        else{
            if(s[index]!='0'){
                int n1 = count(s, index+1, dp);
                int n2 = 0;
                if(index+1<s.size()&&((s[index]<='2'&&s[index+1]<='6')||(s[index]<='1'&&s[index+1]<='9'))) {
                    n2 = count(s, index+2, dp);
                    cout<<index<<endl;
                }
                return dp[index] = n1+n2;
            }
            else return 0;
        }
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return count(s, 0, dp);
    }
};
