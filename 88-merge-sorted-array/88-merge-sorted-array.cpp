class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> ans;
        int idx1=0,idx2=0;
        while(idx1<m and idx2<n) {
            if(a[idx1]<=b[idx2]) {
                ans.push_back(a[idx1++]);
            }
            else {
                ans.push_back(b[idx2++]);
            }
        }
        while(idx1<m) {
            ans.push_back(a[idx1++]);
        }
        while(idx2<n) {
            ans.push_back(b[idx2++]);
        }
        swap(ans,a);
    }
};