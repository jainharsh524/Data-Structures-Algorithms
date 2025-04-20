class Solution {
    static int[] flip(int[] arr){
        for(int i =0;i<arr.length/2;i++){
            int temp = arr[i];
            arr[i] = arr[arr.length-i-1];
            arr[arr.length-i-1] = temp;
        }
        return arr;
    }
    static int[][] invert(int[][] arr){
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                if(arr[i][j]==0) arr[i][j]=1;
                else arr[i][j] = 0;
            }
        }
        return arr;
    }
    public int[][] flipAndInvertImage(int[][] image) {
        for(int i=0;i<image.length;i++){
            image[i] = flip(image[i]);
        }
        image = invert(image);
        return image;
    }
}
