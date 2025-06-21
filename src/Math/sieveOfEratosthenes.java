package Math;

public class sieveOfEratosthenes {
    //Algo:
    // In this function we are taking an extra space of a boolean array of size N.
    // we are accessing the indexes like if that index is false
    // then mark all of its multiple true.
    // It means that all the numbers which are divisible by any other prime number
    // They are marked as Composite numbers.
    public static void primeTillN(int n) {
        boolean[] arr = new boolean[n];
        for (int i = 2; i*i <  n; i++) {
            if(!arr[i]) {
                for (int j = i * 2; j < arr.length; j = j + i) {
                    arr[j] = true;
                }
            }
        }
        System.out.println("Prime Numbers till N are: ");
        for (int i = 0; i < arr.length; i++) {
            if(!arr[i]) System.out.print(i+" ");
        }
    }
    //Time Complexity: O(N*log(log(N)))
    //Space Complexity: O(N)
    public static void main(String[] args) {
        primeTillN(40);
    }
}
