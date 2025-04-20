class Solution {
    public int diagonalSum(int[][] mat) {
        int sum =0;
        int i =0;
        int ptr1 = 0;
        int ptr2 = mat[0].length-1;
        while(i<mat.length ){
            if(ptr1!=ptr2) sum = sum + mat[i][ptr1] + mat[i][ptr2];
            else sum = sum+mat[i][ptr1];
            ptr1++;
            ptr2--;
            i++;
        }
        return sum;
    }
}
