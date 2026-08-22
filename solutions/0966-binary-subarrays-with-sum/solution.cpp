class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        unordered_map<int, int> mp;
        int prefix = 0;
        mp[0] = 1;
        for (int i = 0;i<nums.size();i++){
            prefix = prefix+nums[i];
            if(mp.count(prefix - goal)) ans += mp[prefix - goal];
            mp[prefix]++;
        }
        return ans;
    }
};
