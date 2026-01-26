class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res = "";
        for(char ch: s){
            if(st.empty()) st.push(ch);
            else if(st.top()==ch) st.pop();
            else st.push(ch);
        }
        while(!st.empty()){
            res = st.top()+res;
            st.pop();
        }
        return res;
    }
};
