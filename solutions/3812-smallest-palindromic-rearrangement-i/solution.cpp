class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        int n = s.size();
        string ans((n+1)/2, ' ');
        int left = 0;
        for (int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                ans[left++] = char('a' + i);
                freq[i] -= 2;
            }
            if (freq[i] == 1) ans[s.size() / 2] = char('a' + i);
        }
        string fh = ans;
        if(s.size()%2==0) reverse(ans.begin(), ans.end());
        else{
            if(!ans.empty()) ans.pop_back();
            reverse(ans.begin(), ans.end());
        }
        return fh+ans;
    }
};
