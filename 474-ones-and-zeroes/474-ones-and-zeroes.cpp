class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<int>> cnt(sz,vector<int>(2));
        for(int i=0;i<sz;i++) {
            for(auto j:strs[i]) {
                cnt[i][j-'0']++;
            }
        }
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        for(int i=1;i<=sz;i++) {
            for(int j=0;j<=m;j++) {
                for(int k=0;k<=n;k++) {
                    if(cnt[i-1][0]>j or cnt[i-1][1]>k) {
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                    else {
                        dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-cnt[i-1][0]][k-cnt[i-1][1]]+1);
                    }
                }
            }
        }
        return dp[sz][m][n];
    }
};