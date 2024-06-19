class Solution {
public:
    vector<int> prev_smaller(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        
        vector<int> prev_smaller_idx(n);
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                prev_smaller_idx[i] = -1;
            }
            else {
                while(not st.empty() and arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    prev_smaller_idx[i] = -1;
                }
                else {
                    prev_smaller_idx[i] = st.top();
                }
            }
            st.push(i);
        }
        return prev_smaller_idx;
    }
    
    vector<int> next_smaller(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        
        vector<int> next_smaller_idx(n);
        for(int i=n-1;i>=0;i--) {
            if(st.empty()) {
                next_smaller_idx[i] = n;
            }
            else {
                while(not st.empty() and arr[st.top()] >= arr[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    next_smaller_idx[i] = n;
                }
                else {
                    next_smaller_idx[i] = st.top();
                }
            }
            st.push(i);
        }
        return next_smaller_idx;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next_smaller_idx = next_smaller(heights);
        vector<int> prev_smaller_idx = prev_smaller(heights);
        
        int ans = 0, n = heights.size();
        for(int i=0;i<n;i++) {
            int curr_height = heights[i];
            int curr_width = next_smaller_idx[i] - prev_smaller_idx[i] - 1;
            int curr_area = curr_height * curr_width;
            ans = max(ans, curr_area);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m);
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '0') {
                    height[j] = 0;
                }
                else {
                    height[j]++;
                }
            }
            for(auto j:height) {
                cout<<i<<" ";
            }
            cout<<'\n';
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};