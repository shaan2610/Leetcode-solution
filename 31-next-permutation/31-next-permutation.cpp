class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n=a.size(),chk=0;
        for(int i=n-2;i>=0;i--) {
            if(a[i]<a[i+1]) {
                int mn=a[i+1],idx=i+1;
                for(int j=i+1;j<n;j++) {
                    if(a[j]>a[i] and a[j]<mn) {
                        mn=a[j];
                        idx=j;
                    }
                }
                swap(a[i],a[idx]);
                sort(a.begin()+i+1,a.end());
                chk++;
                break;
            }
        }
        if(not chk) {
            sort(a.begin(),a.end());
        }
    }
};