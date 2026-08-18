class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int sum = 0;
        int pge = 0;
        vector<int> pg(height.size(), 0);
        for(int i = l;i<height.size();i++){
            pge = max(height[i], pge);
            pg[i] = pge;
        }
        vector<int> ng(height.size(), 0);
        int nge = 0;
        for(int i = r;i>=0;i--){
            nge = max(height[i], nge);
            ng[i] = nge;
        }
        vector<int> res(height.size());
        for(int i = 0;i<height.size();i++) res[i] = min(ng[i], pg[i]); 
        for(int i = 0;i<height.size();i++) sum = sum+res[i]-height[i]; 
        return sum;
    }
};
