class Solution {
    public static boolean isSubsequence(String s, String p){
        int i = 0;
        int j= 0;
        while (i<s.length()&&j<p.length()){
            if(s.charAt(i)==p.charAt(j)) {
                j++;
            }
            i++;
        }
        return j==p.length();
    }
    public static String deleteMultipleIndexes(String str, int[] indexes, int start, int end) {
        StringBuilder sb = new StringBuilder(str);
        List<Integer> indexList = new ArrayList<>();
        for (int i = start; i <= end; i++) {
            indexList.add(indexes[i]);
        }
        Collections.sort(indexList, Collections.reverseOrder());
        for (int index : indexList) {
            sb.deleteCharAt(index);
        }

        return sb.toString();
    }

    public static int maximumRemovals(String s, String p, int[] removable) {
//        for (int i = 0; i < removable.length; i++) {
//            sb.deleteCharAt(removable[i]);
//            if(!isSubsequence(sb.toString(), p)) return i;
//        }
        int high = removable.length-1;
        int low = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            String del = deleteMultipleIndexes(s, removable, 0, mid);
            System.out.println(del);
            if(!isSubsequence(del, p)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
}
