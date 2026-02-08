class MinStack {
public:
    stack<int> st;
    stack<int> mst;
    stack<int> msthelper;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(mst.empty()){
            mst.push(val);
        }
        else{
            if(mst.top()>val){
                mst.push(val);
            }
            else{
                while(!mst.empty()&&mst.top()<val){
                    int n = mst.top();
                    msthelper.push(n);
                    mst.pop();
                }
                mst.push(val);
                while(!msthelper.empty()){
                    int n = msthelper.top();
                    mst.push(n);
                    msthelper.pop();
                }
            }
        }
    }
    void pop() {
        int val = st.top();
        st.pop();
        while(!mst.empty()&&mst.top()!=val){
            int n = mst.top();
            mst.pop();
            msthelper.push(n);
        }
        mst.pop();
        while(!msthelper.empty()){
            int n = msthelper.top();
            mst.push(n);
            msthelper.pop();
        }
    }
    int top() {
        return st.top();
    }
    int getMin() {
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
