class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> res(nums1.size(), 0);
        for(int i = 0;i<nums2.size();i++){
            while(!st.empty()&&st.top()<nums2[i]){
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i = 0;i<nums1.size();i++){
            if(mp.count(nums1[i])>0){
                res[i] = mp[nums1[i]];
            }
            else res[i] = -1;
        }
        return res;
    }
};
