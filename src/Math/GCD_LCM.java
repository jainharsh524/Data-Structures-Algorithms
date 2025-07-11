package Math;

public class GCD_LCM {
    static int gcd(int a, int b) {
        if (a == 0) {
            return b;
        }
        return gcd(b%a, a);
    }
    static int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }
}
