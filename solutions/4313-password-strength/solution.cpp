class Solution {
public:
    int passwordStrength(string password) {
        unordered_map <char, int> mp;
        for(char ch: password){
            mp[ch]++;
        }
        int cnt = 0;
        for(auto it: mp){
            if((it.first>='a'&&it.first<='z'))cnt++;
            else if(it.first>='A'&&it.first<='Z') cnt+=2;
            else if(it.first>='0'&&it.first<='9') cnt+=3;
            else if(it.first=='!'||it.first=='@'||it.first=='#'||it.first=='$') cnt+=5;
        }
        return cnt;
    }
};
