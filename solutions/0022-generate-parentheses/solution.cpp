class Solution {
public:
    void generate(int i, int count, vector<string> &res, string temp){
        if(count==0&&i==0){ 
            res.push_back(temp);
            return;
        }
        if(i==0&&count!=0) return;
        generate(i-1, count+1, res, temp+"(");
        if(count>0) generate(i-1, count-1, res, temp+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n*2, 0, res, "");
        return res;
    }
};
