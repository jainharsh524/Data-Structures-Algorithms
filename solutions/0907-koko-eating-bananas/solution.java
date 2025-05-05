class Solution {
   public static int max(int[] arr){
        int max = arr[0];
        for (int i = 0; i < arr.length; i++) if(max<arr[i]) max = arr[i];
        return max;
    }
    public static long timeCalculation(int[] arr, int speed){
        long sum = 0;
        for (int i = 0; i < arr.length; i++) {
            int time = arr[i]/speed;
            if(arr[i]%speed==0) sum+=time;
            else sum = sum+time+1;
        }
        return sum;
    }

    public static int minEatingSpeed(int[] piles, int h) {
        int low = 1;
        int high = max(piles);
        if(h==piles.length) return max(piles);
        else{
            while(low<=high){
                int mid = low+(high-low)/2;
                long time = timeCalculation(piles, mid);
                System.out.println(time);
                if(time>h) low = mid+1;
                else high = mid-1;
            }
        }
        return low;
    }
}
