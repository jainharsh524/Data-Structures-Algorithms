class Solution {
    public int maxProduct(int n) {
        int product = 1;
        int[] arr = new int[(int)Math.log(n)+1];
        int i =0;
        while(n>0){
            int digit = n%10;
            arr[i] = digit;
            i++;
            n = n/10;
        }
        Arrays.sort(arr);
        return product*arr[arr.length-1]*arr[arr.length-2];
    }
}
