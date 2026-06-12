class Solution {
public:
    vector<string> res;
    vector<char> ops = {'+', '-', '*'};
    int n;

    void solve(string &num, int idx, string &currString,
               long long currValue, long long target, long long prevOperand) {
        if (idx >= n && currValue == target) {
            res.push_back(currString);
            return;
        }
        if (idx >= n) return;
        long long digit = 0;
        for (int i = idx; i < n; i++) {
            if (i > idx && num[idx] == '0') break;
            digit = digit * 10 + (num[i] - '0');
            string number = num.substr(idx, i - idx + 1);
            if (idx == 0) {
                int oldLength = currString.size();
                currString += number;
                solve(num, i + 1, currString, digit, target, digit);
                currString.resize(oldLength);
                continue;
            }
            for (int j = 0; j < 3; j++) {
                int oldLength = currString.size();
                if (ops[j] == '+') {
                    currString.push_back('+');
                    currString += number;
                    solve(num, i + 1, currString,
                          currValue + digit, target, digit);
                    currString.resize(oldLength);
                }
                if (ops[j] == '-') {
                    currString.push_back('-');
                    currString += number;

                    solve(num, i + 1, currString,
                          currValue - digit, target, -digit);

                    currString.resize(oldLength);
                }
                if (ops[j] == '*') {
                    long long newValue =
                        currValue - prevOperand + (prevOperand * digit);

                    currString.push_back('*');
                    currString += number;

                    solve(num, i + 1, currString,
                          newValue, target, prevOperand * digit);

                    currString.resize(oldLength);
                }
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string curr;
        n = num.size();
        solve(num, 0, curr, 0LL, (long long)target, 0LL);
        return res;
    }
};
