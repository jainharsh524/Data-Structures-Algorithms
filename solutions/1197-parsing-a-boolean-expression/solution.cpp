class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(auto x : expression){
            if(x == ',') continue;
            if(x != ')'){
                st.push(x);
            }
            else{
                int f = 0 , t = 0;
                while(st.top() != '('){
                    auto y = st.top(); st.pop();
                    y == 't'?  t++ : f++;
                }
                st.pop();
                auto top = st.top();st.pop();
                if(top == '|'){
                    if(t) st.push('t');
                    else st.push('f');
                }else if(top=='&'){
                    if(f) st.push('f');
                    else st.push('t');
                }
                else{
                    if(t) st.push('f');
                    else st.push('t');
                }
            }
        }
        auto t = st.top();
        return (t == 't')? true : false;
    }
};
