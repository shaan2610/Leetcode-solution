class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        // dp[i][j] --> no of ways to reach cell (i, j) from (0, 0)
        // ans --> dp[n-1][m-1]
        
        vector<vector<int>> dp(n, vector<int>(m));
        
        // Corner cases
        // If starting point has an obstacle or dest have an obstacle
        if(obstacleGrid[0][0] == 1 or obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        
        // Base case
        dp[0][0] = 1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // Checking if there is an obstacle in the current cell
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if(i - 1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if(j - 1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    }
};