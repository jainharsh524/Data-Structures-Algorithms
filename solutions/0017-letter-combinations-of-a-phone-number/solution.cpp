class Solution {
public:
    void comb(string& digits, int index, unordered_map<int, string>& mp, string temp, vector<string>& res){
        if(index==digits.size()) res.push_back(temp);
        int num = digits[index] - '0';
        string val = mp[num];
        for(char ch: val){
            temp.push_back(ch);
            comb(digits, index+1, mp, temp, res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
        string temp;
        comb(digits, 0, mp, temp, res);
        return res;
    }
};
