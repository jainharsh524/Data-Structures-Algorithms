class Solution {
public:
    bool match(string& s, string& p, int index1, int index2,
               vector<vector<int>>& dp) {
        if (index1 == s.size() && index2 == p.size())
            return true;
        if (index1 == s.size()) {
            if (p[index2] == '*')
                return match(s, p, index1, index2 + 1, dp);
            else
                return false;
        }
        if (dp[index1][index2] != -1)
            return dp[index1][index2];
        if (p[index2] == '?' || s[index1] == p[index2]) {
            return dp[index1][index2] = match(s, p, index1 + 1, index2 + 1, dp);
        } else if (p[index2] == '*') {
            return dp[index1][index2] =
                       match(s, p, index1 + 1, index2, dp) || //* can be matched with multiple char
                       match(s, p, index1 + 1, index2 + 1, dp) || //* can be matched with one char
                       match(s, p, index1, index2 + 1, dp); //* is epsilon
        } else
            return dp[index1][index2] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, 
        vector<int>(p.size()+1, -1));
        return match(s, p, 0, 0, dp);
    }
};
