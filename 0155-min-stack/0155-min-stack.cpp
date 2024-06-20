class MinStack {
public:
    stack<int> st, min_stack;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min_stack.empty()) {
            min_stack.push(val);
        }
        else {
            int curr_min = min(val, min_stack.top());
            min_stack.push(curr_min);
        }
    }
    
    void pop() {
        if(not st.empty()) {
            st.pop();
            min_stack.pop();
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
        if(min_stack.empty()) {
            return -1;
        }
        int min_val = min_stack.top();
        return min_val;
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