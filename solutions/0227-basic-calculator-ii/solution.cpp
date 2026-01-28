class Solution {
public:
    int priority(char op) {
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

    int calculate(string s) {
        stack<int> num;
        stack<char> oper;
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res = res * 10 + (s[i] - '0');
            }
            else if (s[i] == ' ') continue;
            else {
                num.push(res);
                res = 0;
                while (!oper.empty() && priority(s[i]) <= priority(oper.top())) {
                    char op = oper.top(); oper.pop();
                    int a = num.top(); num.pop();
                    int b = num.top(); num.pop();

                    int val;
                    if (op == '+') val = b + a;
                    else if (op == '-') val = b - a;
                    else if (op == '*') val = b * a;
                    else val = b / a;

                    num.push(val);
                }
                oper.push(s[i]);
            }
        }
        num.push(res);
        while (!oper.empty()) {
            char op = oper.top(); oper.pop();
            int a = num.top(); num.pop();
            int b = num.top(); num.pop();
            int val;
            if (op == '+') val = b + a;
            else if (op == '-') val = b - a;
            else if (op == '*') val = b * a;
            else val = b / a;
            num.push(val);
        }
        return num.top();
    }
};

