class Solution {
public:
    void addStrings(string &res, string &str) {
        if (res == "") {
            res = str;
            return;
        }
        int i = res.size() - 1;
        int j = str.size() - 1;
        int carry = 0;
        string temp = "";
        while (i >= 0 || j >= 0 || carry) {
            int a = 0;
            int b = 0;
            if (i >= 0) {
                a = res[i] - '0';
            }
            if (j >= 0) {
                b = str[j] - '0';
            }
            int sum = a + b + carry;
            carry = sum / 10;
            temp = char(sum % 10 + '0') + temp;
            i--;j--;
        }
        res = temp;
    }

    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        int shift = 0;
        for (int j = num2.size() - 1; j >= 0; j--) {
            int mul = num2[j] - '0';
            int carry = 0;
            string curr = "";
            for (int i = num1.size() - 1; i >= 0; i--) {
                int val = mul * (num1[i] - '0') + carry;
                carry = val / 10;
                curr = char(val % 10 + '0') + curr;
            }
            if (carry)
                curr = char(carry + '0') + curr;
            curr.append(shift, '0');
            shift++;
            addStrings(res, curr);
        }
        return res;
    }
};
