class Solution {
public:
    int dp[1001][1001];
    int fun(int i,int j,string &s,string &t){
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=fun(i-1,j-1,s,t)+fun(i-1,j,s,t);
        }else{
            return dp[i][j]=fun(i-1,j,s,t);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n=s.length(),m=t.length();
        return fun(n-1,m-1,s,t);
    }
};
