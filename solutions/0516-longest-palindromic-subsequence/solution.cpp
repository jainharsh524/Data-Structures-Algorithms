class Solution {
public:
    int commonsubseq(string &s1, string &s2, int index1, int index2, vector<vector<int>>& dp){
        // if(index1>=s1.size()||index2>=s2.size()) return 0;
        if(index1<0||index2<0) return 0;
        if(dp[index1][index2]!=-1) return dp[index1][index2];
        if(s1[index1]==s2[index2]){
            return dp[index1][index2] = 1+commonsubseq(s1, s2, index1-1, index2-1, dp);
        }
        else {
            return dp[index1][index2] = max(commonsubseq(s1, s2, index1, index2-1, dp), commonsubseq(s1, s2, index1-1, index2, dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return commonsubseq(s, t, s.size()-1, t.size()-1, dp);
    }
};
