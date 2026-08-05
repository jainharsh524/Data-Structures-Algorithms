class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int l = 0, h = n1;

        //binary search for cut1 and make cut2 according to cut1
        //cut1 denotes no. of elements we are taking from array1 to make left sorted half.
        //similarly, for cut2
        while(l <= h){
            int cut1 = l + (h - l) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;
//left1 denotes the max ele from array1 which will be in left sorted half
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
//right1 denotes the min ele from array1 ewhich will be in right sorted half.
            int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
//left2 denotes the max ele from array2 which will be in left sorted half
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
//right2 denotes the min ele from array2 ewhich will be in right sorted half.
            int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1){
                if((n1 + n2) % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if(left1 > right2){
                h = cut1 - 1;
            }
            else{
                l = cut1 + 1;
            }
        }
        return 0.0;
    }
};
