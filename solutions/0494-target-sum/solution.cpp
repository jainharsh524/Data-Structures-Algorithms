class Solution {
public:
    int count(vector<int>& nums, int target, int index, vector<vector<int>> &dp){
        if(index>nums.size()) return 0;
        if((target==0)&&(index==(nums.size()))) return 1;
        if((target!=0)&&(index==(nums.size()))) return 0;
        if(dp[index][target+10000]!=-1) return dp[index][target+10000];
        else{
            // cout<<target<<endl;
            int pos = count(nums, target-nums[index], index+1, dp);
            int neg = count(nums, target+nums[index], index+1, dp);
            return dp[index][target+10000] = pos+neg;
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(20001, -1));
        return count(nums, target, 0, dp);
    }
};
