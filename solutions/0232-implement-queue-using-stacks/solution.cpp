class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {}

    void push(int x) {
        // Move everything to st2
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Push new element
        st1.push(x);

        // Move everything back
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int ele = st1.top();
        st1.pop();
        return ele;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty();
    }
};

