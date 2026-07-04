class Solution {
public:
    vector<int> nse(vector<int>& nums){
        stack<pair<int, int>> st;
        vector<int> res(nums.size());
        for(int i = nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top().first>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({nums[i], i});
                res[i] = nums.size();
            }
            else{
                res[i] = st.top().second;
                st.push({nums[i], i});
            }
        }
        return res;
    }
    vector<int> pse(vector<int>& nums){
        stack<pair<int, int>> st;
        vector<int> res(nums.size());
        for(int i = 0;i<nums.size();i++){
            while(!st.empty()&&st.top().first>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                st.push({nums[i], i});
                res[i] = -1;
            }
            else if(st.top().first<nums[i]){
                res[i] = st.top().second;
                st.push({nums[i], i});
            }
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        vector<int> psv = pse(heights);
        vector<int> nsv = nse(heights);
        for(int i = 0;i<heights.size();i++){
            int psei = psv[i]+1;
            int nsei = nsv[i]-1;
            int area = (nsei-psei+1)*heights[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
