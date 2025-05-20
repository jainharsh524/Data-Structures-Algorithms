package String;

public class stringBuffer {

    public static void main(String[] args) {

        // 1. Creating a StringBuffer
        StringBuffer sb = new StringBuffer("Java");

        // 2. append() - adds data to end
        sb.append(" Programming");
        System.out.println("After append: " + sb);

        // 3. insert() - inserts data at specific index
        sb.insert(5, "Awesome ");
        System.out.println("After insert: " + sb);

        // 4. delete() - removes characters between start (inclusive) and end (exclusive)
        sb.delete(5, 13);
        System.out.println("After delete: " + sb);

        // 5. deleteCharAt() - removes a character at given index
        sb.deleteCharAt(4);
        System.out.println("After deleteCharAt: " + sb);

        // 6. replace() - replaces substring from start to end with another string
        sb.replace(0, 4, "Core");
        System.out.println("After replace: " + sb);

        // 7. reverse() - reverses the entire string buffer
        sb.reverse();
        System.out.println("After reverse: " + sb);

        // 8. length() - current number of characters
        System.out.println("Length: " + sb.length());

        // 9. capacity() - current buffer capacity (default is 16 + initial string length)
        System.out.println("Capacity: " + sb.capacity());

        // 10. ensureCapacity() - ensures the internal buffer is large enough
        sb.ensureCapacity(100);
        System.out.println("Capacity after ensureCapacity(100): " + sb.capacity());

        // 11. setCharAt() - changes a character at specific index
        sb.setCharAt(0, 'Z');
        System.out.println("After setCharAt(0, 'Z'): " + sb);

        // 12. charAt() - retrieves character at index
        System.out.println("charAt(0): " + sb.charAt(0));

        // 13. substring() - returns substring, same as String
        System.out.println("substring(0, 4): " + sb.substring(0, 4));

        // 14. toString() - converts to String object
        String str = sb.toString();
        System.out.println("Converted to String: " + str);

        // Demonstrating thread-safety (conceptually)
        demonstrateThreadSafety();
    }

    // Basic example of how StringBuffer is thread-safe
    private static void demonstrateThreadSafety() {
        StringBuffer sharedBuffer = new StringBuffer("ThreadSafe");

        Runnable task = () -> {
            for (int i = 0; i < 5; i++) {
                sharedBuffer.append("X");
                System.out.println(Thread.currentThread().getName() + ": " + sharedBuffer);
            }
        };

        Thread t1 = new Thread(task, "Thread-1");
        Thread t2 = new Thread(task, "Thread-2");

        t1.start();
        t2.start();
    }
}

