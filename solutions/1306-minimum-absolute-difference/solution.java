class Solution {
    public static List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> lst = new ArrayList<>();
        int minDifference = arr[arr.length-1]*10;
        for (int i = 1; i < arr.length; i++) {
            int diff = arr[i]-arr[i-1];
            if(minDifference>Math.abs(diff)) minDifference = diff;
        }
        for (int i = 1; i < arr.length; i++) {
            int diff = arr[i]-arr[i-1];
            if(Math.abs(diff)==minDifference) {
                List<Integer> lst1 = new ArrayList<>();
                lst1.add(0,Math.min(arr[i], arr[i-1]));
                lst1.add(1,Math.max(arr[i], arr[i-1]));
                lst.add(lst1);
            }
        }
        return lst;
    }
}
