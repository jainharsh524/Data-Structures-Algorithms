class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> res(3, -1);
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='a') res[0] = i;
            if(s[i]=='b') res[1] = i;
            if(s[i]=='c') res[2] = i;
            if(s[0]!=-1&&s[1]!=-1&&s[2]!=-1){
                cnt = cnt+1+min(res[0], min(res[1], res[2]));
            }
        }
        return cnt;
    }
};
