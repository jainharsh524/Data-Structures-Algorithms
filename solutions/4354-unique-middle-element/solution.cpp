class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int ele: nums) mp[ele]++;
        int n = nums.size();
        return mp[nums[n/2]]==1;
    }
};
