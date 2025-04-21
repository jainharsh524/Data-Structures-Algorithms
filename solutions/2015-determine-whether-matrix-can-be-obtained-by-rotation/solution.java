class Solution {
    public boolean findRotation(int[][] a, int[][] b) {
      int len =a.length;
        int count_90 =0, count_180 =0, count_270 =0, count_0 =0;
        for(int i = 0; i< len; i++)
        {
            for(int j = 0; j< len; j++)
            {
                if(b[i][j]==a[len -j-1][i]) 
                    count_90++;
                if(b[i][j]==a[len -i-1][len -j-1])
                    count_180++;
                if(b[i][j]==a[j][len -i-1])
                    count_270++;
                if(b[i][j]==a[i][j])
                    count_0++;
            }
        }
        if(count_90 == len * len || count_270 == len * len || count_180 == len * len || count_0 == len * len)
            return true;
        else return false;
    }
}
