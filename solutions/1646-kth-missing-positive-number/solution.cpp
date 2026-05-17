class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0;
        int h = arr.size()-1;
        while(l<=h){
            int m = l+(h-l)/2;
            int left = arr[m]-m-1;
            if(left<k) l = m+1;
            else h = m-1;
        }
        return h+k+1;
    }
};
