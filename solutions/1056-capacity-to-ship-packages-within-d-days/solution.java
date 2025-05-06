class Solution {
    public static int max(int[] arr){
        int max = arr[0];
        for (int i = 0; i < arr.length; i++) if(max<arr[i]) max = arr[i];
        return max;
    }
    public static int sum(int[] arr){
        int sum = 0;
        for (int element : arr) sum+=element;
        return sum;
    }
    public static long timeCalculation(int[] arr, int cap){
        long sum = 0;
        int day = 0;
        int i =0;
        while (i< arr.length){
            sum = sum+arr[i];
            if(sum==cap) {
                day++;sum=0;
            }
            else if(sum>cap) {
                sum = 0;
                i--;day++;
            }
            else if (i == arr.length - 1 && sum!=0 && sum < cap) day++;
            i++;
        }
        return day;
    }
    public static int shipWithinDays(int[] weights, int days) {
        int low = max(weights);
        int high = sum(weights)*2/days;
        while(low<=high){
            int mid = low+(high-low)/2;
            long time = timeCalculation(weights, mid);
            if(time> days) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
}
