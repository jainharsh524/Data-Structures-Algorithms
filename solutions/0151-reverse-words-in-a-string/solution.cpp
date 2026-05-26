class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0;
        int r = 0;
        while(l<s.size()){
            if(s[l]==' '){
                s.erase(r, 1);
            }
            else break;
        }
        while(r<s.size()){
            if(s[r]==' '){
                reverse(s.begin() + l, s.begin() + r);
                r++;
                while(r<s.size()&&s[r]==' '){
                    s.erase(r, 1);
                }
                l = r;
            }
            else r++;
        }
        reverse(s.begin()+l, s.end());
        r--;
        if(s[r]==' ') s.erase(r, 1);
        return s;
    }
};
