class Solution {
    public static int minIndex(int[] arr){
        int minElementIndex = 0;
        for(int i =0;i<arr.length;i++){
            if(arr[minElementIndex] >arr[i]) minElementIndex = i;
        }
        return minElementIndex;
    }
    public static boolean checkMax(int[][] matrix, int col, int row){
        for(int i =0;i<matrix.length;i++){
            if(!(matrix[row][col]>=matrix[i][col])) return false;
        }
        return true;
    }
    public List<Integer> luckyNumbers(int[][] matrix) {
        List<Integer> luckyNumber= new ArrayList<>();
        for(int i =0;i< matrix.length;i++){
            int col = minIndex(matrix[i]);
            if(checkMax(matrix, col, i)) luckyNumber.add(matrix[i][col]);
        }
        return luckyNumber;
    }
}
