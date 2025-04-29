class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        int l1 = nums1.length;
        int l2 = nums2.length;
        int i = 0, j = 0;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> ls = new ArrayList<>();
        while( i < l1 && j < l2)
        {
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
            else
            {
                ls.add(nums1[i]);
                i++;j++;
            }
        }
        int[] arr = new int[ls.size()];
        for (int l = 0; l < arr.length; l++) {
            arr[l] = ls.get(l);
        }
        return arr;
    }
}
