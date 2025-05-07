Here are concise and clear notes on **Bubble Sort**:

---

### 📘 **Bubble Sort – Overview**
Bubble Sort is a **simple comparison-based sorting algorithm**. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

---

### 🧠 **Concept**
- Compare adjacent elements.
- Swap if left element is **greater** than the right.
- After each full pass, the **largest unsorted element "bubbles up" to its correct position**.
- Continue this process for all elements.

---

### 🔁 **Algorithm Steps**
1. Loop through the array from start to end.
2. For each pass:
   - Compare adjacent elements.
   - Swap if needed.
3. After each pass, the largest element is placed at the end.
4. Repeat `n-1` times or until no swaps are made (optimized version).

---

### ✅ **Optimized Version**
Add a boolean flag (`swapped`) to stop if no swaps were made in a pass → **Best-case O(n)** for sorted arrays.

---

### ⏱ **Time Complexity**
| Case    | Comparisons | Swaps            |
|---------|-------------|------------------|
| Best    | O(n)        | 0 (if optimized) |
| Average | O(n²)       | Depends          |
| Worst   | O(n²)       | O(n²)            |

---

### 🧮 **Space Complexity**
- **O(1)** (in-place sorting)

---

### 📌 **When to Use**
- Simple datasets
- Teaching purposes
- Small arrays where performance isn't critical

---

### 🚫 **When *Not* to Use**
- Large datasets
- Performance-sensitive applications
