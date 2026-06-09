class Solution {
public:
    bool isPalin(string s, int index1, int index2){
        while(index1<index2){
            if(s[index1]!=s[index2]) return false;
            index1++;
            index2--;
        }
        return true;
    }
    void generate(string &s, int index, vector<string> temp, vector<vector<string>>& res){
        if(index==s.size()){
            res.push_back(temp);
        }
        for(int i = index;i<s.size();i++){
            if(isPalin(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                generate(s, i+1, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        generate(s, 0, temp, res);
        return res;
    }
};
