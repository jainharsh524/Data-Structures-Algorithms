class Solution {
public:
    string Say(string s){
        vector<pair<char, int>> mp;
        int count = 0;
        for(int i = 0;i<s.size();i++){
            if(i<s.size()-1&&s[i]!=s[i+1]){
                count++;
                mp.push_back({s[i], count});
                count = 0;
            }
            else if(i==s.size()-1){
                count++;
                mp.push_back({s[i], count});
            }
            else{
                count++;
            }
        }
        for(int i = 0;i<mp.size();i++){
            cout<<mp[i].first<<" "<<mp[i].second<<endl;
        }
        string res = "";
        for(int i = 0;i<mp.size();i++){
            res = res+to_string(mp[i].second);
            res = res+mp[i].first;
        }
        return res;
    }
    string countAndSay(int n) {
        string val = "1";
        for(int i = 1;i<n;i++){
            val = Say(val);
        }
        return val;
    }
};
