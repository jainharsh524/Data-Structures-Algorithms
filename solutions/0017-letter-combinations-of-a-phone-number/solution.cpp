class Solution {
public:
    void generate(string &digits, string temp, vector<string>& res, unordered_map<char, string> &mp, int index){
        if(index==digits.size()){
            res.push_back(temp);
            return;
        }
        string val = mp[digits[index]];
        for(char ch: val){
            temp.push_back(ch);
            generate(digits, temp, res, mp, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> res;
        string temp = "";
        generate(digits, temp, res, mp, 0);
        return res;
    }
};
