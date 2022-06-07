class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pref(n);
        pref[0]=height[0];
        for(int i=1;i<n;i++) {
            pref[i]=max(pref[i-1],height[i]);
        }
        int mx=0,ans=0;
        for(int i=n-1;i>=0;i--) {
            mx=max(mx,height[i]);
            ans+=(min(mx,pref[i])-height[i]);
        }
        return ans;
    }
};