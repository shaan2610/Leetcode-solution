class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        // dp[i][j] --> no of ways to reach cell (i, j) from (0, 0)
        // ans --> dp[n-1][m-1]
        
        // vector<vector<int>> dp(n, vector<int>(m));
        vector<int> new_dp(m), old_dp(m);
        
        // Corner cases
        // If starting point has an obstacle or dest have an obstacle
        if(obstacleGrid[0][0] == 1 or obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }
        
        // Base case
        new_dp[0] = 1;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // Checking if there is an obstacle in the current cell
                if(obstacleGrid[i][j] == 1) {
                    new_dp[j] = 0;
                    continue;
                }
                if(i == 0 and j == 0) {
                    continue;
                }
                new_dp[j] = 0;
                if(i - 1 >= 0) {
                    new_dp[j] += old_dp[j];
                }
                if(j - 1 >= 0) {
                    new_dp[j] += new_dp[j-1];
                }
            }
            swap(new_dp, old_dp);
        }
        return old_dp[m-1];
    }
};