class Solution {
public:
    string decodeString(string s) {
        stack<int> num;
        stack<string> alpha;

        int res = 0;
        string val = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                res = res * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                num.push(res);
                alpha.push(val);
                res = 0;
                val = "";
            }
            else if (isalpha(s[i])) {
                val += s[i];
            }
            else if (s[i] == ']') {
                int repeat = num.top(); num.pop();
                string prev = alpha.top(); alpha.pop();
                string expanded = "";
                while (repeat--) {
                    expanded += val;
                }
                val = prev + expanded;
            }
        }
        return val;
    }
};

