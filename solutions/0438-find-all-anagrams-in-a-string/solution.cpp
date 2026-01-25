class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map <char, int> mp;
        for( char ch: p){
            mp[ch]++;
        }
        int left = 0;
        int count = p.size();
        vector<int>res;
        for(int right = 0;right<s.size();right++){
            if(mp[s[right]]>0) count--;
            mp[s[right]]--;
            if(right-left+1>p.size()){
                mp[s[left]]++;
                if(mp[s[left]]>0) count++;
                left++;
            }
            if(count==0){
                res.push_back(left);
            }
        }
        return res;
    }
};
