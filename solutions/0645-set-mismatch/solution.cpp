class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        // Cyclic sort
        for (int i = 0; i < n; ) {
            int Index = nums[i] - 1;

            if (nums[i] != nums[Index]) {
                swap(nums[i], nums[Index]);
            } else {
                i++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return {nums[i], i + 1};
            }
        }

        return {};
    }
};

