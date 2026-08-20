class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        for(int ele: asteroids){
            if(ele > 0) st.push(ele);
            else{
                while(!st.empty() && st.top() > 0 && st.top()<(-ele)){
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(ele);
                }
                if(!st.empty() && st.top()==(-ele)){ st.pop(); continue;}
            }
        }

        while(!st.empty()){ res.push_back(st.top()); st.pop();}
        reverse(res.begin(), res.end());
        return res;
    }
};
