class Solution {
public:
    void generate(vector<int>& nums, int index, vector<int> temp, vector<vector<int>>& res){
        if(index>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        generate(nums, index+1, temp, res);
        temp.pop_back();
        generate(nums, index+1, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        generate(nums, 0, temp, res);
        return res;
    }
};
