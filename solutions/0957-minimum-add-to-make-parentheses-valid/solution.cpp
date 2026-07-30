class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s=="") return 0;
        // int cnt = 0;
        // for(char ch: s){
        //     if(ch=='(') cnt++;
        //     else cnt--;
        // }
        // return abs(cnt);
        stack<char> st;
        for(char ch: s){ 
            if(!st.empty()&&(st.top()=='(')&&(ch==')')) st.pop();
            else st.push(ch);
        }
        return st.size();
    }
};
