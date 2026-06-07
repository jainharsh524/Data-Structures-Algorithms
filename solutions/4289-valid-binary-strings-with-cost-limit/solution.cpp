class Solution {
public:
    vector<vector<int>> dp;
    void generate(int prev, string temp, vector<string>& res, int i){
        if(i<=0){ 
            res.push_back(temp); 
            return;
        }
        if(prev!=1) generate(1, temp+"1", res, i-1);
        generate(0, temp+"0", res, i-1);
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        dp.assign(n + 1, vector<int>(2, -1));
        generate(0, "", res, n);
        vector<string> ans;
        for(string str: res){
            int cost = 0;
            for(int i = 0;i<str.size();i++){
                if(str[i]=='1')cost+=i;
            }
            if(cost<=k)ans.push_back(str);
        }
        return ans;
    }
};
