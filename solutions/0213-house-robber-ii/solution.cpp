class Solution {
public:
    int val(vector<int>& nums, vector<vector<int>>& dp, int curr, bool flag){
        if(curr >= nums.size()) return 0;

        // if first house was taken, skip last
        if(flag && curr == nums.size() - 1) return 0;

        if(dp[curr][flag] != -1) return dp[curr][flag];

        int take, skip;

        if(curr == 0){
            take = nums[curr] + val(nums, dp, curr + 2, true);
            skip = val(nums, dp, curr + 1, false);
        }
        else{
            take = nums[curr] + val(nums, dp, curr + 2, flag);
            skip = val(nums, dp, curr + 1, flag);
        }

        return dp[curr][flag] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return val(nums, dp, 0, false);
    }
};
