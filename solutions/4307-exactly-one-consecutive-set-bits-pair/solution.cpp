class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        string s = bitset<32>(n).to_string();
        for(int i = 0;i<s.size()-1;i++){
            if(s[i]=='1'&&s[i+1]=='1') count++;
        }
        return count==1;
    }
};
