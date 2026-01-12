class Solution {
public:
    int search(vector<int>& nums, int target){
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==target) return m;
            else if(nums[m]<target) l = m+1;
            else h = m-1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0;i<numbers.size();i++){
            int nT = target-numbers[i];
            // cout<<nT<<" ";
            int index = search(numbers, nT);
            // cout<<index<<endl;
            if(index!=-1&&index!=i){
                if(index<i){
                    res.push_back(index+1);
                    res.push_back(i+1);
                }
                else{
                    res.push_back(i+1);
                    res.push_back(index+1);
                }
                return res;
            }
        }
        return res;
    }
};
