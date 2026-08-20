class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz, 0);
        stack<int> st;
        for(int i = 2*sz-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i % sz]){
                st.pop();
            }
            if(!st.empty()) res[i % sz] = st.top();
            else res[i % sz] = -1;
            st.push(nums[i % sz]);
        }
        return res;
    }
};
