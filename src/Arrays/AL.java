package Arrays;

import java.util.ArrayList;
import java.util.Scanner;

public class AL {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // Syntax
        ArrayList<Integer> list = new ArrayList<>(5);

        list.add(67);
        list.add(234);
        list.add(654);
        list.add(43);
        list.add(654);
        list.add(8765);
        //size of arraylist is fixed internally.
        //but when a list is filled till certain indexes, it creates another arrayList of double the size of current size.
        //it copies all the elements of the old arrayList, and deletes the old arrayList.
        //time complexity for this procedure is O(1).
//        System.out.println(list.contains(765432));
//        System.out.println(list);
        list.set(0, 99); //sets 0th index's value 99.
//
        list.remove(2); //removes the index 2
//
//        System.out.println(list);

        // input
        for (int i = 0; i < 5; i++) {
            list.add(in.nextInt());
        }

        // get item at any index
        for (int i = 0; i < 5; i++) {
            System.out.println(list.get(i)); // pass index here, list[index] syntax will not work here
        }
        System.out.println(list);

    }
}
