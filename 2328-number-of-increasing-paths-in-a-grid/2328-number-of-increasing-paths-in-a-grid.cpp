class Solution {
public:
    
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,1,-1};
    
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp) {
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int n=grid.size(),m=grid[0].size(),mod=1e9+7;
        
        auto chkBound = [&] (int x,int y) {
            return (x>=0 and x<n and y>=0 and y<m);
        };
        
        int ans=1;
        for(int dir=0;dir<4;dir++) {
            int nx=i+dx[dir],ny=j+dy[dir];
            if(chkBound(nx,ny) and grid[nx][ny]>grid[i][j]) {
                ans=(ans+solve(nx,ny,grid,dp))%mod;
            }
        }
        return dp[i][j]=ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                solve(i,j,grid,dp);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};