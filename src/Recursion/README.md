
## 📘 Recursion in Java

### 🔁 What is Recursion?

Recursion is a programming technique where a method calls itself to solve a problem.

---

### 🔑 Key Concepts:

1. **Base Case**:

    * The condition under which recursion stops.
    * Prevents infinite recursion.
    * Every recursion must eventually reach a base case.

2. **Recursive Case**:

    * The part of the function that reduces the problem into smaller subproblems.
    * Calls the function itself with a modified parameter.

---

### 🔄 General Structure of Recursive Function:

```java
returnType function(parameters) {
    if (base_condition) {
        return some_value;
    }
    return function(smaller_problem);
}
```

---

## 🧠 Types of Recursion

### 1. **Tail Recursion**

* Recursive call is the **last** statement.
* No computation after the recursive call.

```java
void tailRec(int n) {
    if (n == 0) return;
    System.out.println(n);
    tailRec(n - 1); // tail call
}
```

### 2. **Head Recursion**

* Recursive call occurs **before** processing.

```java
void headRec(int n) {
    if (n == 0) return;
    headRec(n - 1); // head call
    System.out.println(n);
}
```

---

## 🔍 How Recursion Works Internally:

* Each recursive call gets its **own stack frame**.
* Control returns **after** the recursive call finishes.

---

## 📦 Applications of Recursion:

* Factorial, Fibonacci
* Tree traversals
* Backtracking (e.g., Sudoku, N-Queens)
* Divide & Conquer (e.g., Merge Sort, Quick Sort)
* Dynamic Programming (with Memoization)

---

## ⚠️ Pitfalls:

* Missing base case → StackOverflowError
* Infinite recursion
* Too deep recursion → use iteration if possible

---

## 🔁 Recursion vs Iteration:

| Feature      | Recursion                | Iteration           |
| ------------ | ------------------------ | ------------------- |
| Stack usage  | Uses call stack          | Uses loop variables |
| Readability  | More expressive          | Often faster        |
| Memory usage | More (due to call stack) | Less                |

---

## 🧩 Tips:

* Always define a **clear base case**.
* Dry-run recursive problems with pen and paper.
* Use **memoization** to optimize overlapping subproblems.
* For large depth, consider converting recursion to **iteration**.
