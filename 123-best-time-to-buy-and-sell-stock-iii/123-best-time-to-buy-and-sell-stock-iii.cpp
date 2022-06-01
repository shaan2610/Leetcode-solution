class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        vector<int> suff(n);
        int mx=a[n-1];
        for(int i=n-2;i>=0;i--) {
            suff[i]=max({suff[i],suff[i+1],mx-a[i]});
            mx=max(mx,a[i]);
        }
        int mn=a[0],ans=suff[0];
        for(int i=1;i<n;i++) {
            ans=max(ans,max(a[i]-mn,0)+(i==n-1 ? 0:suff[i+1]));
            mn=min(mn,a[i]);
        }
        return ans;
    }
};