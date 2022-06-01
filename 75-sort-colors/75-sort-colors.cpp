class Solution {
public:
    void sortColors(vector<int>& a) {
        int idx=0,n=a.size();
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                swap(a[i],a[idx++]);
            }
        }
        for(int i=0;i<n;i++) {
            if(a[i]==1) {
                swap(a[i],a[idx++]);
            }
        }
    }
};