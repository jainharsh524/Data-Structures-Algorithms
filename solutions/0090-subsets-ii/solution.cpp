class Solution {
public:
    void sst(vector<vector<int>>& res, vector<int>& arr, int idx, int n,
             vector<int>& nums) {
        res.push_back(arr);

        for (int i = idx; i < n; i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            arr.push_back(nums[i]);
            sst(res, arr, i + 1, n, nums);
            arr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> arr;

        sst(res, arr, 0, nums.size(), nums);

        return res;
    }
};
