class Solution {
    public static int bSearch(int[] arr, int target){
        int low = 0;
        int high = arr.length-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(target==arr[mid]) return mid;
            else if(target>arr[mid]) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    public static int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> hs = new HashSet<>();
        int ptr = 0;
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        if(nums1.length<nums2.length){
            while(ptr <nums1.length){
                int index = bSearch(nums2, nums1[ptr]);
                if(index!=-1) hs.add(nums1[ptr]);
                ptr++;
            }
        }
        else{
            while(ptr <nums2.length){
                int index = bSearch(nums1, nums2[ptr]);
                if(index!=-1) hs.add(nums2[ptr]);
                ptr++;
            }
        }
        Integer[] arr = hs.toArray(new Integer[hs.size()]);
        int[] arr1 = new int[arr.length];
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = arr[i];
        }
        return arr1;
    }
}
