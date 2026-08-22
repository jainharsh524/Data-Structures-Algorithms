class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        unordered_map<int, int> mp;
        int maxlen = 0;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp[0]>k){
                mp[nums[l]]--;
                l++;
            }
            maxlen = max(maxlen, i-l+1);
        }
        return maxlen;
    }
};
