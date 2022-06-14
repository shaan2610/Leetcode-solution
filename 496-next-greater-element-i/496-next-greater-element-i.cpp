class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        unordered_map<int,int> gr;
        for(int i=n-1;i>=0;i--) {
            if(st.empty()) {
                gr[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else {
                while(not st.empty() and st.top()<=nums2[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    gr[nums2[i]]=-1;
                    st.push(nums2[i]);
                }
                else {
                    gr[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for(auto i:nums1) {
            ans.push_back(gr[i]);
        }
        return ans;
    }
};