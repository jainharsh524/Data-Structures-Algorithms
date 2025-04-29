class Solution {
    public int findKthPositive(int[] arr, int k) {
        int missingNumbers = arr[arr.length-1]-arr.length;
        if(missingNumbers<k){
            missingNumbers = k-missingNumbers;
            return arr[arr.length-1]+missingNumbers;
        }
        else{
            for (int i = 0; i < arr.length; i++) {
                int missingNumberTillNow = arr[i]-i-1;
                if(missingNumberTillNow>=k){
                    missingNumberTillNow = arr[i]-i-1;
                    return arr[i]+k-missingNumberTillNow-1;
                }
            }
        }
        return 0;
    }
}
