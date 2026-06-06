class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(vector<int>& nums,string& s,int i,int precov) {
        int n = nums.size();
        if(i >= n)
            return 0;
        if(dp[i][precov] != -1) return dp[i][precov];
        if(s[i] == '0') {
            return dp[i][precov] =solve(nums, s, i + 1, 0);
        }
        long long ans = 0;
        ans = nums[i] + solve(nums, s, i + 1, 1);
        if(i > 0 && !precov) {
            ans = max(ans, (long long)nums[i - 1] + solve(nums,s, i + 1, 0));
        }
        return dp[i][precov] = ans;
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        dp.assign(n, vector<long long>(2, -1));
        return solve(nums, s, 0, 0);
    }
};
