class Solution {
public:
    bool isAnagram(string s, string t) {
        // unordered_set<char> st;
        unordered_map<char, int> st;
        if(s.size()!=t.size()) return false;
        for(int i = 0;i<s.size();i++){
            if(st.find(s[i])==st.end()) st.insert({s[i], 1});
            else st[s[i]] = st[s[i]]+1;
        }
        for( char c: t){
            if(st.find(c)==st.end()){
                return false;
            }
            else {
                st[c] = st[c]-1;
                if(st[c]==0) st.erase(c);
            }
        }
        cout<<st.size();
        return st.empty();
    }
};
