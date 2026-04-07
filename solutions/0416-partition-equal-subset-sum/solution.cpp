class Solution {
public:
    bool possible(vector<int>& nums, int target, int index, vector<vector<int>>& dp){
        if(target<0) return false;
        if(index == nums.size()) {
            if(target == 0) return true;
            else return false;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool take = possible(nums, target-nums[index], index+1, dp);
        bool left = possible(nums, target, index+1, dp);
        return dp[index][target] = take||left;
    }
    bool canPartition(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(20001, -1));
        int sum = 0;
        for(int i: nums) sum +=i;
        if((sum&1)==1) return false;
        else return possible(nums, sum/2, 0, dp);
    }
};
