class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st1;
        vector<int> left(n);
        int ans=0;
        for(int i=0;i<n;i++) {
            if(st1.empty()) {
                left[i]=-1;
            }
            else {
                while(not st1.empty() and heights[st1.top()]>=heights[i]) {
                    st1.pop();
                }
                if(st1.empty()) {
                    left[i]=-1;
                }
                else {
                    left[i]=st1.top();
                }
            }
            st1.push(i);
        }
        while(not st1.empty()) {
            st1.pop();
        }
        for(int i=n-1;i>=0;i--) {
            if(st1.empty()) {
                ans=max(ans,(n-left[i]-1)*heights[i]);
            }
            else {
                while(not st1.empty() and heights[st1.top()]>=heights[i]) {
                    st1.pop();
                }
                if(st1.empty()) {
                    ans=max(ans,(n-left[i]-1)*heights[i]);
                }
                else {
                    ans=max(ans,(st1.top()-left[i]-1)*heights[i]);
                }
            }
            st1.push(i);
        }
        return ans;
    }
};