class Solution {
public:
    int findMin(unordered_map<int, int> &mp){
        int mini = INT_MAX;
        for(auto &ele: mp) mini = min(ele.second, mini);
        return mini;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int minIndex = 0;
        int countsubs = 0;
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
            while(mp.size() > k){
                if(mp[nums[l]] == l) mp.erase(nums[l]);
                l++;
            }
            if(mp.size() == k){
                int minIndex = findMin(mp);
                countsubs = countsubs + minIndex + 1 - l;
            }
        }
        return countsubs;
    }
};
