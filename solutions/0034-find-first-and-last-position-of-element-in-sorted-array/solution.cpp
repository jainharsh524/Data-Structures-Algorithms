class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int left = binarySearch(nums, target, 0, nums.size() - 1, true);
        if (left == -1) {
            return result;
        }
        int right = binarySearch(nums, target, 0, nums.size() - 1, false);
        result[0] = left;
        result[1] = right;
        return result;
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right, bool findLeft) {
        if (left > right) {
            return -1;
        }
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            if (findLeft) {
                int leftIndex = binarySearch(nums, target, left, mid - 1, findLeft);
                return (leftIndex == -1) ? mid : leftIndex;
            } else {
                int rightIndex = binarySearch(nums, target, mid + 1, right, findLeft);
                return (rightIndex == -1) ? mid : rightIndex;
            }
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, right, findLeft);
        } else {
            return binarySearch(nums, target, left, mid - 1, findLeft);
        }
    }
};
