class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> mp;
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int target = -nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r){
                int val = nums[l]+nums[r];
                if(val==target){
                    mp.insert({nums[i], nums[l], nums[r]});
                    r--;
                }
                else if(val<target) l++;
                else r--;
            }
        }
        for(auto ele: mp) res.push_back(ele);
        return res;
    }
};
