class MinStack {
public:
    stack<pair<int,int>> minst;
    stack<pair<int,int>> st;
    int counter;
    MinStack() {
        counter = 0;
    }
    void push(int value) {
        if(minst.empty() || value < minst.top().first) minst.push({value,counter});
        else st.push({value,counter});
        counter++;
    }
    
    void pop() {
        if(st.empty()) minst.pop(); 
        else if(minst.empty()) st.pop(); 
        else if(st.top().second > minst.top().second) st.pop(); 
        else minst.pop(); 
    }
    
    int top() {
        if(st.empty()) return minst.top().first;
        if(minst.empty()) return st.top().first;
        if(st.top().second > minst.top().second) return st.top().first;
        return minst.top().first;
    }
    int getMin() {
        return minst.top().first;
    }
};
