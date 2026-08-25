class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> temp;
        int right = mid+1, left = low;
        while(left <= mid && right <= high){
            if(nums[right] < nums[left]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = low; i<= high;i++){
            nums[i] = temp[i - low];
        };
    }
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        int cnt = 0;
        for(int i = low;i<=mid;i++){
            while(right <= high && nums[i] > 2LL*nums[right]) right++;
            cnt += right - mid - 1;
        }
        return cnt;
    }
    int sorting(vector<int>& nums, int low, int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += sorting(nums, low, mid);
        cnt += sorting(nums, mid+1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return sorting(nums, 0, nums.size()-1);
    }
};
