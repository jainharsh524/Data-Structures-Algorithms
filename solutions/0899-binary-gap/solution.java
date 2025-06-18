class Solution {
    public int binaryGap(int num) {
        int pos = 0;
        int lastOcc = -1;
        int maxGap = 0;
        while (num>0){
            int gap = 0;
            int end = num&1;
            if(end==1) {
                if(lastOcc==-1) {
                    maxGap = 0;
                }
                else {
                    gap = pos - lastOcc;
                    if (gap > maxGap) maxGap = gap;
                }
                lastOcc = pos;
            }
            num = num>>1;
            pos++;
        }
        return maxGap;
    }
}
