package Math;

public class bitwiseOperators {
    public static void main(String[] args) {
        int a = 5;  // 0101
        int b = 3;  // 0011

        System.out.println("a = " + a + ", b = " + b);

        // AND
        System.out.println("a & b = " + (a & b));  // 0101 & 0011 = 0001 → 1

        // OR
        System.out.println("a | b = " + (a | b));  // 0101 | 0011 = 0111 → 7

        // XOR
        System.out.println("a ^ b = " + (a ^ b));  // 0101 ^ 0011 = 0110 → 6

        // NOT
        System.out.println("~a = " + (~a));        // ~0101 = 1010 → -6 (2's complement)

        // Left Shift
        System.out.println("a << 1 = " + (a << 1));  // 0101 << 1 = 1010 → 10

        // Right Shift (Arithmetic)
        System.out.println("a >> 1 = " + (a >> 1));  // 0101 >> 1 = 0010 → 2

        // Unsigned Right Shift
        int negative = -5;
        System.out.println("negative >>> 1 = " + (negative >>> 1)); // Logical right shift
    }
}
