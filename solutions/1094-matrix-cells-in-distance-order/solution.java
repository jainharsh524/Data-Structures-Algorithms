class Solution {
    public int[][] allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        int [][] arr = new int[rows][cols];
        int num=0;
       
            //filling values inside the array
                for(int i=0 ; i<rows ; i++){
                    for(int j=0 ; j<cols ; j++){
                    arr[i][j]=Math.abs(i-rCenter)+Math.abs(j-cCenter);
                    }
                }
           int max=arr[0][0];
           //finding the maximum value in the array
           for(int i=0 ; i<arr.length ; i++){
                for(int j=0 ; j<arr[0].length ; j++){
                    if(arr[i][j]>max){
                        max=arr[i][j];
                    }
                }
           }
             int [][] rvalue = new int[rows*cols][2];
             int index=0;
           while(num<=max){
               for(int l=0 ; l<arr.length ; l++){
                    for(int m=0 ; m<arr[0].length ; m++){
                        if(arr[l][m]==num){
                            rvalue[index][0]=l;
                            rvalue[index][1]=m;
                            index++;
                        }
                        
                    }
                }
                num++;
           }
      return rvalue;
    }
}
