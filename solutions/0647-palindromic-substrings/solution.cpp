class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int start = 0;
        //all 1 length strings 
        for(int i = 0;i<s.size();i++){
            dp[i][i] = 1;
            count++;
        }
        int len = s.size();
        for(int i = 2;i<=len;i++){
            for(int j = 0;j+i-1<len;j++){
                int k = j+i-1;
                if(s[j]==s[k]){
                    if(i<=2||dp[j+1][k-1]==1){
                        dp[j][k] = 1;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
