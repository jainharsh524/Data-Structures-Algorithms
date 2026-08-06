class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = s.size() - 1;
        int r = 0;
        while (r < s.size() && s[r] == ' ') r++;
        s.erase(0, r);
        int l = s.size() - 1;
        while (l >= 0 && s[l] == ' ') l--;
        s.erase(l + 1);
        reverse(s.begin(), s.end());
        i = 0;
        r = 0;
        while (r < s.size()) {
            while (r < s.size() && s[r] != ' ')
                r++;
            reverse(s.begin() + i, s.begin() + r);
            int start = r;
            while (r < s.size() && s[r] == ' ')
                r++;
            if (r - start > 1)
                s.erase(start + 1, r - start - 1);
            i = start + 1;
            r = i;
        }
        return s;
    }
};
