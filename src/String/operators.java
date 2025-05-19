package String;
import java.util.*;
public class operators {
    public static void main(String[] args) {
        System.out.println('a' + 'b');//char addition, answer converted into integer
        System.out.println("a" + "b");//concatenation
        System.out.println((char)('a' + 3));

        System.out.println("a" + 1);
        // this is same as after a few steps: "a" + "1"
        // integer will be converted to Integer that will call toString()

        System.out.println("Harsh" + new ArrayList<>());
        System.out.println("Harsh" + new Integer(56));
        String ans = new Integer(56) + "" + new ArrayList<>();
        System.out.println(ans);

        System.out.println("a" + 'b');
    }
}
