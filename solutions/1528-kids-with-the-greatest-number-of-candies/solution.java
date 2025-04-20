class Solution {
   static int findMax(int[] arr){
        int max = arr[0];
        for(int i =0;i<arr.length;i++){
            if(arr[i]>max) max = arr[i];
        }
        return max;
    }
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        ArrayList<Boolean> list = new ArrayList<Boolean>();
        for (int i =0;i<candies.length;i++){
            if(candies[i]+extraCandies>=findMax(candies)) list.add(true);
            else list.add(false);
        }
        return list;
    }
}
