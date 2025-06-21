package Bitwise;
import java.util.*;

public class grayCode {
    //### Why does `i ^ (i >> 1)` work?
    //
    //XORing with a right‑shifted copy achieves this:
    //
    //* For the most‑significant bit (MSB), `i>>1` contributes 0, so the MSB in Gray code equals the MSB of `i`.
    //* For every lower bit `k`, the Gray‑code bit is the XOR of bit `k` and bit `k+1` of `i`.
    //  – If the two original bits differ, the Gray bit is 1; if they’re the same, it’s 0.
    //  – This encoding guarantees that only one bit flips when `i` increments by 1.
    //
    //Mathematically, this is equivalent to the *binary‑to‑Gray* conversion formula
    //
    //```
    //G_k = B_k ⊕ B_{k+1}
    //```
    public List<Integer> grayCode(int n) {
        List<Integer> result = new LinkedList<>();
        for (int i = 0; i < 1<<n; i++) result.add(i ^ i>>1);
        return result;
    }
    public static void main(String[] args) {

    }
}
