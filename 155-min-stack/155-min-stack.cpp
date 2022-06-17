class MinStack {
public:
    vector<long long> arr;
    long long mn;
    MinStack() {
        mn=INT_MAX;
    }
    
    void push(int val) {
        if(arr.empty()) {
            mn=val;
            arr.push_back(val);
            return;
        }
        if(val<mn) {
            arr.push_back(2ll*val-mn);
            mn=val;
        }
        else {
            arr.push_back(val);
        }
    }
    
    void pop() {
        if(arr.empty()) {
            return;
        }
        if(arr.back()>=mn) {
            arr.pop_back();
        }
        else {
            mn=2*mn-arr.back();
            arr.pop_back();
        }
    }
    
    int top() {
        if(arr.empty()) {
            return -1;
        }
        if(arr.back()>=mn) {
            return arr.back();
        }
        else {
            return mn;
        }
    }
    
    int getMin() {
        if(arr.empty()) {
            return -1;
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