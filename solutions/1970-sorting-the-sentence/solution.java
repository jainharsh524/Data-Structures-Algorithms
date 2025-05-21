class Solution {
    public static String[] swap(String[] s, int index1, int index2){
        String temp = s[index1];
        s[index1] = s[index2];
        s[index2] = temp;
        return s;
    }
    public static String sortSentence(String s) {
        String[] arr = s.split(" ");
        int i = 0;
        while(i<arr.length){
            int strLength = arr[i].length();
            if(arr[i].charAt(strLength-1)-49!=i){
                swap(arr, i, arr[i].charAt(strLength-1)-49);
            }
            else i++;
        }
        s = "";
        for (int j = 0; j < arr.length; j++) {
            s = s+arr[j].replaceAll("\\d+", " ");
        }
        return s.trim();
    }
}
