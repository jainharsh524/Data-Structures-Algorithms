class Solution {
   public static int[] countBits(int n) {
        int[] arr = new int[n+1];
        if(n==0){
            arr[0] = 0;
        }
        else if(n>=1) {
            arr[0] = 0;
            arr[1] = 1;
            int i = 2;
            int j = 0;
            if(n==2){
                j = 3;
            }
            else j = 4;
            while(j<=n+1){
                int count = 0;
                while(i<j){
                    arr[i] = arr[count]+1;
                    count++;i++;
                }
                if(j<n+1) {
                    j = Math.min(j * 2, n+1);
                }
                else break;
            }
        }
        return arr;
    }
}
