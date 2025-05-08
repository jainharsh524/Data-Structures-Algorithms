Here's a clear and concise explanation of **Selection Sort**:

---

### 📘 **Selection Sort – Overview**
Selection Sort is a **simple comparison-based sorting algorithm**. It works by **repeatedly finding the minimum (or maximum) element** from the unsorted part of the array and **placing it at the beginning**.

---

### 🔁 **Algorithm Steps**
1. Start from the first element (index `i`).
2. Find the **minimum element** from index `i` to the end of the array.
3. Swap this minimum element with the element at index `i`.
4. Move to the next index and repeat steps 2–3.
5. Continue until the entire array is sorted.

---

### 🧠 **Concept**
- Divide the array into **sorted** and **unsorted** parts.
- Continuously pick the smallest element from the unsorted part and move it to the sorted part.
- In each iteration, the sorted part grows, and the unsorted part shrinks.

---

### ⏱ **Time Complexity**
| Case       | Comparisons | Swaps |
|------------|-------------|-------|
| Best       | O(n²)       | O(n)  |
| Average    | O(n²)       | O(n)  |
| Worst      | O(n²)       | O(n)  |

> Unlike bubble sort, the number of swaps is minimal — only one per iteration.

---

### 🧮 **Space Complexity**
- **O(1)** (in-place sorting)

---

### ✅ **Pros**
- Simple to understand and implement
- Performs well for **small** datasets

---

### 🚫 **Cons**
- Inefficient on large lists
- Not stable (relative order of equal elements may change)

---
