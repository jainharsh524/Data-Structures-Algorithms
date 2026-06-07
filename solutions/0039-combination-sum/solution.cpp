class Solution {
public:
    void generate(vector<int>& comb, int index, int target, vector<int> temp, set<vector<int>>& res){
        if(target==0) res.insert(temp);
        if(index>=comb.size()) return;
        if(target<0) return;
        temp.push_back(comb[index]);
        generate(comb, index, target-comb[index], temp, res);
        temp.pop_back();
        generate(comb, index+1, target, temp, res);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> temp;
        generate(candidates, 0, target, temp, res);
        vector<vector<int>>res1;
        for(auto ele: res){
            res1.push_back(ele);
        }
        return res1;
    }
};
