class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans=0,n=a.size();
        for(int i=0;i<n-1;i++) {
            if(a[i+1]>a[i]) {
                ans+=(a[i+1]-a[i]);
            }
        }
        return ans;
    }
};