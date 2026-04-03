class Solution {
public:
    int val(vector<int>& nums, vector<int>&dp, int curr){
        if(curr>=nums.size()) return 0;
        if(dp[curr]!=-1) return dp[curr];
        else{
            int took = nums[curr]+val(nums, dp, curr+2);
            int skip = val(nums, dp, curr+1);
            dp[curr] = max(took, skip);
            return dp[curr];
        }
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return val(nums, dp, 0);
    }
};
