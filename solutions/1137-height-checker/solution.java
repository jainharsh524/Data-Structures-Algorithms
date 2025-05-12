class Solution {
public static int heightChecker(int[] heights) {
        
    	int n = heights.length;
    	int[] sorted =  Arrays.copyOf(heights, n);
    	int count = 0;
    	Arrays.sort(sorted);
    		
 
    	for (int i = 0; i < n; i++) {
			
    		
    		if(sorted[i] != heights[i]) {
    			count ++;
    		}
		}
    	return count;
    }
}
