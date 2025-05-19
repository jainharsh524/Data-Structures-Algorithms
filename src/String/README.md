
# Java: String, StringBuilder, and StringBuffer

## 📘 Overview

Java provides three primary classes to handle character sequences:

- `String`: Immutable and thread-safe.
- `StringBuilder`: Mutable and not thread-safe.
- `StringBuffer`: Mutable and thread-safe.

---

## 📌 String

### ✅ Key Characteristics
- **Immutable**: Once created, it cannot be changed.
- **Stored in the String Pool** for memory optimization.
- **Thread-safe** due to immutability.

### 🔧 Commonly Used Methods

| Method | Description |
|--------|-------------|
| `length()` | Returns string length |
| `charAt(int index)` | Returns char at index |
| `substring(start, end)` | Extracts substring |
| `toLowerCase()` / `toUpperCase()` | Case conversion |
| `indexOf(String str)` | Index of first match |
| `equals(Object obj)` | Value comparison |
| `compareTo(String str)` | Lexicographic compare |
| `replace(old, new)` | Character replacement |
| `trim()` | Removes leading/trailing spaces |
| `split(String regex)` | Splits using regex |
| `valueOf(anyType)` | Converts to string |

### 🔍 Internal Working

- Internally backed by a `final char[]`.
- Operations return **new** objects to preserve immutability.
- Hashcode is cached once calculated.

---

## 🚀 StringBuilder

### ✅ Key Characteristics
- **Mutable**: Directly modifies character sequence.
- **Faster** for non-threaded environments.
- **Not thread-safe**.

### 🔧 Commonly Used Methods

| Method | Description |
|--------|-------------|
| `append(anyType)` | Adds data at the end |
| `insert(int offset, anyType)` | Inserts at position |
| `delete(int start, int end)` | Deletes substring |
| `replace(int start, end, str)` | Replaces a part |
| `reverse()` | Reverses string |
| `capacity()` | Internal buffer size |
| `ensureCapacity(int minCap)` | Ensures capacity |
| `setCharAt(int index, ch)` | Sets character |
| `toString()` | Converts to `String` |

### 🔍 Internal Working

- Uses a resizable char array internally:
  ```java
  char[] value;
  int count;

* Initial capacity: 16 chars. Auto-expands as needed: `newCapacity = (old * 2) + 2`.

---

## 🧵 StringBuffer

### ✅ Key Characteristics

* **Mutable** like `StringBuilder`.
* **Thread-safe** via synchronized methods.
* Slightly **slower** than `StringBuilder` due to locking overhead.

### 🔧 Commonly Used Methods

| Method                        | Description         |
| ----------------------------- | ------------------- |
| `append(anyType)`             | Adds text to end    |
| `insert(int offset, anyType)` | Inserts value       |
| `delete(int start, end)`      | Removes part        |
| `replace(start, end, str)`    | Replaces characters |
| `reverse()`                   | Reverses sequence   |
| `capacity()`                  | Buffer capacity     |
| `ensureCapacity(minCap)`      | Grows buffer        |
| `setCharAt(index, ch)`        | Updates char        |
| `toString()`                  | Returns string form |

### 🔍 Internal Working

* Also backed by a `char[]`.
* All methods are **synchronized**, providing **thread safety**:

---

## 🆚 Comparison Table

| Feature     | String          | StringBuilder  | StringBuffer       |
| ----------- | --------------- | -------------- | ------------------ |
| Mutability  | Immutable       | Mutable        | Mutable            |
| Thread-safe | Yes (immutable) | No             | Yes (synchronized) |
| Performance | Slower          | Fastest        | Moderate           |
| Use Case    | Constants, keys | Fast local ops | Multi-threaded ops |
| Backed By   | `final char[]`  | `char[]`       | `char[]`           |

---

## 🧠 Tips

* Use `String` for read-only or constant data.
* Use `StringBuilder` for high-performance tasks in single-threaded environments.
* Use `StringBuffer` in multi-threaded programs that require synchronization.

---

## 📚 References

* [String - JavaDocs](https://docs.oracle.com/javase/8/docs/api/java/lang/String.html)
* [StringBuilder - JavaDocs](https://docs.oracle.com/javase/8/docs/api/java/lang/StringBuilder.html)
* [StringBuffer - JavaDocs](https://docs.oracle.com/javase/8/docs/api/java/lang/StringBuffer.html)
