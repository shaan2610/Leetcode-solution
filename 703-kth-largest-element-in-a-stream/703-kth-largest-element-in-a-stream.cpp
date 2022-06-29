class KthLargest {
public:
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int k;
    KthLargest(int k1, vector<int>& nums) {
        k=k1;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if(minHeap.size()<k) {
            minHeap.push(val);
        }
        else if(val>minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */