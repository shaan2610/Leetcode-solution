class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans=a[0],mx=0,n=a.size(),sum=0;
        for(int i=0;i<n;i++) {
            mx+=a[i];
            ans=max(ans,mx);
            if(mx<0) {
                mx=0;
            }
        }
        return ans;
    }
};