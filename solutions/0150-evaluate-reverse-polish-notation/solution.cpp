class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> numStack;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i]!="-"&&tokens[i]!="+"&&tokens[i]!="*"&&tokens[i]!="/"){
                string tok = tokens[i];
                int val = 0;
                int ind = 0;
                bool flag = false;
                while(ind<tok.size()){
                    if(ind==0&&tok[ind]=='-'){
                        flag = true;ind++;continue;
                    }
                    val = val*10+(tok[ind]-'0');
                    ind++;
                }
                if(flag) {val = -val;}
                // cout<<val<<" ";
                numStack.push(val);
            }
            else{
                if(tokens[i]=="+"){
                    int a = numStack.top();
                    numStack.pop();
                    int b = numStack.top();
                    numStack.pop();
                    numStack.push(a+b);
                    cout<<a+b<<" ";
                }
                else if(tokens[i]=="-"){
                    int a = numStack.top();
                    numStack.pop();
                    int b = numStack.top();
                    numStack.pop();
                    numStack.push(b-a);
                    cout<<b-a<<" ";
                }
                else if(tokens[i]=="*"){
                    int a = numStack.top();
                    numStack.pop();
                    int b = numStack.top();
                    numStack.pop();
                    numStack.push(a*b);
                    cout<<a*b<<" ";
                }
                else if(tokens[i]=="/"){
                    int a = numStack.top();
                    numStack.pop();
                    int b = numStack.top();
                    numStack.pop();
                    numStack.push(b/a);
                    cout<<b/a<<" ";
                }
            }
        }
        return numStack.top();
    }
};
