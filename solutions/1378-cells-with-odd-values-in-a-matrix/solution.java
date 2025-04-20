class Solution {
    static int[][] rowIncrement(int[][] arr, int row){
        for(int i=0;i<arr[row].length;i++){
            arr[row][i]++;
        }
        return arr;
    }
    static int[][] colIncrement(int[][] arr, int col){
        for(int j=0;j<arr.length;j++){
            arr[j][col]++;
        }
        return arr;
    }
    public static int oddCells(int m, int n, int[][] indices) {
        int count = 0;
        int[][] arr = new int[m][n];
        for(int i =0;i<indices.length;i++){
            int row = indices[i][0];
            arr = rowIncrement(arr, row);
            int col = indices[i][1];
            arr = colIncrement(arr, col);
        }
        for(int i =0;i< arr.length;i++){
            for (int j = 0; j < arr[i].length; j++) {
                if(arr[i][j]%2==1) count++;
            }
        }
        return count;
    }
}
