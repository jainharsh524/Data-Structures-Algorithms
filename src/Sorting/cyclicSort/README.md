

### 📘 **Cyclic Sort – Overview**
**Cyclic Sort** is a powerful and efficient algorithm used to rearrange elements when:
- The array contains **`n` elements** ranging from **1 to n** (or **0 to n-1**).
- The elements are **distinct** or may involve **duplicates/missing numbers** in some variations.

---

### 🧠 **Concept**
- Iterate through the array.
- For each element, check if it is at the correct index (i.e., `nums[i] == i + 1` for 1 to n).
- If not, **swap it with the element at its correct position**.
- Repeat until all elements are in the correct position.

---

### 🔁 **Algorithm Steps**
1. Start from the beginning of the array.
2. For `nums[i]`, check if it should be at index `nums[i] - 1`.
3. If not, swap `nums[i]` with `nums[nums[i] - 1]`.
4. If it's in the correct position, move to the next index.
5. Continue until the end of the array.

---

### ⏱ **Time Complexity**
- **O(n)** — Each number is placed in its correct index only once.
- **Efficient** for problems where numbers are in a known range.

---

### 🧮 **Space Complexity**
- **O(1)** — In-place sorting.

---

### ✅ **When to Use**
- Problems involving:
    - **Missing numbers**
    - **Duplicate numbers**
    - **Find smallest missing positive integer**
    - **First missing number in a sequence**
- When elements lie within a range of indices.

---

### 🚫 **Limitations**
- Only works when numbers are in a known range (e.g., 0 to n-1 or 1 to n).
- Cannot be directly applied to general sorting.
