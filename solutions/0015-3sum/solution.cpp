class Solution {
public:
    // bool exists(vector<vector<int>>& ans, vector<int>& temp) {
    //     for (auto v : ans) {
    //         if (v == temp) return true;
    //     }
    //     return false;
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    do{
                        j++;
                    }while(nums[j] == nums[j-1] && j < k);
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        // vector<vector<int>> res;
        // unordered_map <int, int> mp;
        // for(int i = 0;i<nums.size();i++){
        //     mp.insert({nums[i], i});
        // }
        // for(int i = 0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         int val = nums[i]+nums[j];
        //         if(mp.find(-val)!=mp.end() && mp[-val]!=i && mp[-val]!=j && i!=j){
        //             vector<int> temp = {nums[i], nums[j], -val};
        //             sort(temp.begin(), temp.end());
        //             if (!exists(res, temp)) {
        //                 res.push_back(temp);
        //             }
        //         }
        //     }
        // }
        return res;
    }
};
