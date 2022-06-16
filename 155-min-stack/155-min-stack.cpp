class MinStack {
public:
    vector<int> arr,mn;
    MinStack() {
        
    }
    
    void push(int val) {
        arr.push_back(val);
        if(mn.empty()) {
            mn.push_back(val);
        }
        else {
            mn.push_back(min(val,mn.back()));
        }
    }
    
    void pop() {
        if(arr.empty()) {
            return;
        }
        arr.pop_back();
        mn.pop_back();
    }
    
    int top() {
        if(arr.empty()) {
            return -1;
        }
        return arr.back();
    }
    
    int getMin() {
        if(mn.empty()) {
            return -1;
        }
        return mn.back();
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