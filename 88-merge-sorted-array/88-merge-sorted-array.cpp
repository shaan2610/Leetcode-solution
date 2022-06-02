class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        int gap=(n+m+1)/2;
        while(gap) {
            int  idx1=0,idx2=gap;
            while(idx2<n+m) {
                if(idx1<n and idx2<n) {
                    if(a[idx1]>a[idx2]) {
                        swap(a[idx1],a[idx2]);
                    }
                }
                else if(idx1<n) {
                    if(a[idx1]>b[idx2-n]) {
                        swap(a[idx1],b[idx2-n]);
                    }
                }
                else {
                    if(b[idx1-n]>b[idx2-n]) {
                        swap(b[idx1-n],b[idx2-n]);
                    }
                }
                idx1++;
                idx2++;
            }
            if(gap==1) {
                break;
            }
            gap=(gap+1)/2;
        }
        int idx=n;
        for(auto i:b) {
            a[n++]=i;
        }
    }
};