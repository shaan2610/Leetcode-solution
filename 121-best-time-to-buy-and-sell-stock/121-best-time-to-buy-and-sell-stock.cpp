class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size(),mx=a[n-1],ans=0;
        for(int i=n-2;i>=0;i--) {
            ans=max(ans,mx-a[i]);
            mx=max(mx,a[i]);
        }
        return ans;
    }
};