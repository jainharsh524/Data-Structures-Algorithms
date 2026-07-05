class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;          // Empty prefix
        int prefix = 0;
        int ans = 0;
        for(int x : nums){
            prefix += x;
            if(mp.count(prefix - goal))
                ans += mp[prefix - goal];
            mp[prefix]++;
        }
        return ans;
    }
};
