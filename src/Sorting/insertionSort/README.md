

### 📘 **Insertion Sort – Overview**
Insertion Sort is a simple **comparison-based sorting algorithm** that builds the final sorted array one item at a time.

---

### 🧠 **Concept**
- Start with the second element.
- Compare it with the elements before it.
- Insert it into the correct position in the sorted part of the array.
- Repeat this for all elements.

---

### 🔁 **Algorithm Steps**
1. Start from index `1` (second element).
2. Store the current element as `key`.
3. Compare `key` with previous elements:
    - Shift all elements greater than `key` one position to the right.
4. Insert `key` at the correct location.
5. Repeat until the array is sorted.

---

### ✅ **Best Case (Optimized Version)**
- If the array is already sorted, only comparisons are made.
- **Best-case time complexity: O(n)**

---

### ⏱ **Time Complexity**
| Case       | Time Complexity |
|------------|------------------|
| Best       | O(n)             |
| Average    | O(n²)            |
| Worst      | O(n²)            |

---

### 🧮 **Space Complexity**
- **O(1)** – In-place sorting, no extra memory used.

---

### 📌 **When to Use**
- Small datasets
- When data is **nearly sorted**
- Teaching sorting basics

---

### 🚫 **When *Not* to Use**
- Large datasets
- Performance-critical applications
