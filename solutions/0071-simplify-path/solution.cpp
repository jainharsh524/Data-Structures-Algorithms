class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp;
        for(char ch : path){
            if(ch == '/'){
                if(temp != ""){
                    if(temp == ".."){
                        if(!st.empty()) st.pop();
                    }
                    else if(temp != "."){
                        st.push(temp);
                    }
                    temp = "";
                }
                else continue;
            }
            else temp.push_back(ch);
        }
        if(temp != ""){
            if(temp == ".."){
                if(!st.empty()) st.pop();
            }
            else if(temp != "."){
                st.push(temp);
            }
        }
        vector<string> str;
        while(!st.empty()){
            str.push_back(st.top()); 
            st.pop();
        }
        reverse(str.begin(), str.end());
        string res = "/";
        for(auto ele: str){
            res += ele;
            res.push_back('/');
        }
        res.pop_back();
        return res == "" ? "/" : res;
    }
};
