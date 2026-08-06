class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long val = 0;
        int flag = false;
        while (i < s.size()) {
            if (s[i] == ' ')
                i++;
            else
                break;
        }
        if(i<s.size()&&s[i] == '-'||s[i]=='+') {
            if(s[i]=='-') {flag = !flag;}
            i++;
        }
        while (i < s.size()) {
            if (isdigit(s[i])) {
                val = ((val * 10) + s[i] - '0');
                if(!flag&&(val > INT_MAX)) return INT_MAX;
                if(flag&&(-val < INT_MIN)) return INT_MIN;
                i++;
            } else
                break;
        }
        if (flag)
            return -val;
        return val;
    }
};
