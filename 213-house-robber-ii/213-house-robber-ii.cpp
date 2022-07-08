class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        
        auto calc = [&] (int l,int r) {
            int n=r-l+1;
            vector<int> dp(n+1);
            dp[1]=nums[l];
            for(int i=2;i<=n;i++) {
                dp[i]=max(dp[i-1],dp[i-2]+nums[l+i-1]);
            }
            return dp[n];
        };
        
        int ans=0;
        ans=max(ans,calc(0,n-2));
        ans=max(ans,calc(1,n-1));
        return ans;
    }
};