class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()) {
            return true;
        }
        int sum=0;
        for(auto i:nums) {
            sum+=i;
        }
        if(sum&1) {
            return false;
        }
        int req=sum/2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(req+1));
        for(int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=req;j++) {
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j) {
                    dp[i][j]|=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][req];
    }
};