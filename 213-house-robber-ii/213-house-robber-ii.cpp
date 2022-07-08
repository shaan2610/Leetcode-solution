class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) {
            return nums[0];
        }
        
        auto calc = [&] (vector<int> v) {
            int n1=v.size();
            vector<int> dp(n1+1);
            dp[1]=v[0];
            for(int i=2;i<=n1;i++) {
                dp[i]=max(dp[i-1],v[i-1]+dp[i-2]);
            }
            return dp[n1];
        };
        
        int ans=0;
        for(int i=0;i<n;i++) {
            vector<int> v;
            for(int j=1;j<n;j++) {
                v.push_back(nums[(i+j)%n]);
            }
            ans=max(ans,calc(v));
        }
        return ans;
    }
};