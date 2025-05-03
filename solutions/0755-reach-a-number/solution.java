class Solution {
    public static int reachNumber(int target) {
        int steps = 1;
        int currentValue = 0;
        int moves = 0;
        target = Math.abs(target);
        while(true){
            if(currentValue>=target) {
                if ((currentValue - target) % 2 != 0) {
                    currentValue = currentValue + steps;
                    steps++;
                    moves++;
                } else break;
            }
            else{
                currentValue = currentValue + steps;
                steps++;
                moves++;
            }
        }
        return moves;
    }
}
