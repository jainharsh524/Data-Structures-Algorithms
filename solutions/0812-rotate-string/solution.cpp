class Solution {
public:
    void rotate(string& s){
        char ch = s[0];
        s.erase(0, 1);
        s+=ch;
    }
    bool rotateString(string s, string goal) {
        for(int i = 0;i<s.size();i++){
            rotate(s);
            if(s==goal) return true;
        }
        return false;
    }
};
