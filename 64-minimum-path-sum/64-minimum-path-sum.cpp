class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=grid[i][j];
                int mx=INT_MAX;
                if(i) {
                    mx=min(mx,dp[i-1][j]);
                }
                if(j) {
                    mx=min(mx,dp[i][j-1]);
                }
                if(mx!=INT_MAX) {
                    dp[i][j]+=mx;
                }
            }
        }
        return dp[n-1][m-1];
    }
};