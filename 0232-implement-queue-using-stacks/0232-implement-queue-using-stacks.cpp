class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void transfer_elements() {
        while(not st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()) {
            transfer_elements();
        }
        int val = st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st2.empty()) {
            transfer_elements();
        }
        int val = st2.top();
        return val;
    }
    
    bool empty() {
        return (st1.empty() and st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */