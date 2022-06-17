class StockSpanner {
public:
    stack<int> st;
    int idx=0;
    vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        if(st.empty()) {
            st.push(idx);
            idx++;
            return idx;
        }
        else {
            while(not st.empty() and arr[st.top()]<=price) {
                st.pop();
            }
            if(st.empty()) {
                st.push(idx);
                idx++;
                return idx;
            }
            else {
                int ans=idx-st.top();
                st.push(idx);
                idx++;
                return ans;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */