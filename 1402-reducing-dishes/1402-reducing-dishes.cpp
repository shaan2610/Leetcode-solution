class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
        for(int i=0;i<=n;i++) {
            dp[i][0]=0;
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i<j) {
                    continue;
                }
                dp[i][j]=max({dp[i-1][j-1]+j*satisfaction[i-1],dp[i-1][j]});
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};