class MinStack {
public:
    stack<int> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        if(not st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) {
            return -1;
        }
        else {
            return st.top();
        }
    }
    
    int getMin() {
        stack<int> st1;
        int mn = INT_MAX;
        while(not st.empty()) {
            int val = st.top();
            st.pop();
            mn = min(mn, val);
            st1.push(val);
        }
        
//         Restoring the original stack
        while(not st1.empty()) {
            int val = st1.top();
            st1.pop();
            st.push(val);
        }
        return mn;
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