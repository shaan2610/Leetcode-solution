class MedianFinder {
public:
    
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int,vector<int>> maxHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int maxSize=maxHeap.size(),minSize=minHeap.size();
        if(maxSize==0 or maxHeap.top()>num) {
            maxHeap.push(num);
            maxSize++;
        }
        else {
            minHeap.push(num);
            minSize++;
        }
        if(maxSize>minSize+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minSize>maxSize+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int maxSize=maxHeap.size(),minSize=minHeap.size();
        if(maxSize>minSize) {
            return maxHeap.top();
        }
        else if(minSize>maxSize) {
            return minHeap.top();
        }
        else {
            double ans=(minHeap.top()+maxHeap.top())/2.0;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */