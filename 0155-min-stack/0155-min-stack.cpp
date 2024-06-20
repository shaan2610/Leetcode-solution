class MinStack {
public:
    stack<long long> st;
    long long min_val;
    
    MinStack() {
        min_val = INT_MAX;
    }
    
    void push(int x) {
        if(st.empty()) {
            st.push(x);
            min_val = x;
        }
        else if(x < min_val) {
            st.push(2ll * x - min_val);
            min_val = x;
        }
        else {  // x >= min_val
            st.push(x);
        }
    }
    
    void pop() {
        if(st.top() >= min_val) {
            st.pop();
        }
        else {
            min_val = 2ll * min_val - st.top();   // Roll back to previous minimum
            st.pop();
        }
    }
    
    int top() {
        if(st.top() >= min_val) {
            return st.top();
        }
        else {
            return min_val;
        }
    }
    
    int getMin() {
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