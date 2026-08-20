class Solution {
public:
    vector<int> nse(vector<int>& heights){
        vector<int> res(heights.size(), heights.size());
        stack<int> st;
        for(int i = heights.size()-1; i >= 0 ; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop(); 
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> pse(vector<int>& heights){
        vector<int> res(heights.size(), -1);
        stack<int> st;
        for(int i = 0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop(); 
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsee = nse(heights);
        vector<int> psee = pse(heights);
        int maxarea = 0;
        for(int i = 0;i<heights.size();i++){
            int area = heights[i] * (nsee[i] - psee[i] - 1);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};
