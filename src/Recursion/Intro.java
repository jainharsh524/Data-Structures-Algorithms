package Recursion;

public class Intro {
    //Head Recursion
    public static void printNumbersHead(int n) {
        if (n == 0) return;
        printNumbersHead(n - 1); // recursive call before the print
        System.out.print(n + " ");
    }
    //Tail Recursion
    public static void printNumbersTail(int n) {
        if (n == 0) return;
        System.out.print(n + " ");  // print before recursive call
        printNumbersTail(n - 1);        // recursive call is the last operation
    }
    public static int fibonacci(int n){
        if(n==0) return 0;
        else if(n==1) return 1;
        else return fibonacci(n-1)+fibonacci(n-2);
    }
    public static void main(String[] args) {

        System.out.println(fibonacci(30));
    }
}
