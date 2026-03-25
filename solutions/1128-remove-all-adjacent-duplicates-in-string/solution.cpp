class Solution {
public:
    string removeDuplicates(string s) {
        int index = -1;
        int i = 1;
        while(i>0&&i<s.size()){
            if(s[i-1]==s[i]){
                s.erase(i-1, 2);
                i = i-1;
                cout<<i<<endl;
            }
            else i++;
            if(i==0){
                i = 1;
            }
        }
        return s;
    }
};
