class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st1,st2;
        vector<int> left(n),right(n);
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
        for(int i=n-1;i>=0;i--) {
            if(st2.empty()) {
                right[i]=n;
            }
            else {
                while(not st2.empty() and heights[st2.top()]>=heights[i]) {
                    st2.pop();
                }
                if(st2.empty()) {
                    right[i]=n;
                }
                else {
                    right[i]=st2.top();
                }
            }
            st2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};