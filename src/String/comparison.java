package String;

public class comparison {
    public static void main(String[] args) {
        String a = "Harsh";
        String b = "Harsh";
        String c = a;
//        System.out.println(c == a);
        // ==
//        System.out.println(a == b);

        String name1 = new String("Harsh");
        String name2 = new String("Harsh");

        System.out.println(name1 == name2);

        System.out.println(name1.equals(name2));

    }
}
