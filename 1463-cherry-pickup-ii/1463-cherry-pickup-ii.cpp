class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        dp[0][0][m-1]=grid[0][0]+grid[0][m-1];
        
        vector<int> dy = {-1,0,1};
        
        auto chkBound = [&] (int y) {
            return (y>=0 and y<m);
        };
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                for(int k=0;k<m;k++) {
                    int val;
                    if(j==k) {
                        val=grid[i][j];
                    }
                    else {
                        val=grid[i][j]+grid[i][k];
                    }
                    for(int dir1=0;dir1<3;dir1++) {
                        for(int dir2=0;dir2<3;dir2++) {
                            int ny1=j+dy[dir1],ny2=k+dy[dir2];
                            if(chkBound(ny1) and chkBound(ny2) and dp[i-1][ny1][ny2]!=-1) {
                                dp[i][j][k]=max(dp[i][j][k],val+dp[i-1][ny1][ny2]);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<m;j++) {
            for(int k=0;k<m;k++) {
                ans=max(ans,dp[n-1][j][k]);
            }
        }
        return ans;
    }
};