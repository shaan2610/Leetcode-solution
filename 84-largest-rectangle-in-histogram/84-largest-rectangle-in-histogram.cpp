class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n=heights.size();
        stack<int> st;
        int ans=0;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(i);
            }
            else {
                while(not st.empty() and heights[st.top()]>=heights[i]) {
                    int height=heights[st.top()];
                    st.pop();
                    int width=i-(st.empty() ? -1:st.top())-1;
                    ans=max(ans,height*width);
                }
                st.push(i);
            }
        }
        return ans;
    }
};