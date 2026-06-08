class Solution {
public:
    void generate(int k, int n, int start, vector<int> temp, vector<vector<int>>& res){
        if((k==0)&&(n==0)){ 
            res.push_back(temp);
            return;
        }
        if(k==0) return;
        if(n<0) return;
        if(start>9) return;
        temp.push_back(start);
        generate(k-1, n-start, start+1, temp,res);
        temp.pop_back();
        generate(k, n, start+1, temp, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        if(n>45) return {};
        generate(k, n, 1, temp, res);
        return res;
    }
};
