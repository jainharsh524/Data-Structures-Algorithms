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
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
        commonsubseq(str1, str2, str1.size()-1, str2.size()-1, dp);
        int i = str1.size()-1;
        int j = str2.size()-1;
        string super;
        while(i >= 0 && j >= 0){
            if(str1[i] == str2[j]){
                super += str1[i];
                i--;
                j--;
            }
            else{
                int up = (i>0) ? dp[i-1][j] : 0;
                int left = (j>0) ? dp[i][j-1] : 0;
                if(up >= left){
                    super += str1[i];
                    i--;
                }
                else{
                    super += str2[j];
                    j--;
                }
            }
        }
        while(i >= 0){
            super += str1[i];
            i--;
        }
        while(j >= 0){
            super += str2[j];
            j--;
        }
        reverse(super.begin(), super.end());
        return super;
    }
};
