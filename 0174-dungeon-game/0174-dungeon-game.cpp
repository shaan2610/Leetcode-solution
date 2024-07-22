class Solution {
public:
    
    // Returns min health required to go from (i, j) to  (n-1, m-1)
    int solve(vector<vector<int>>& dungeon, int i, int j, vector<vector<int>> &dp){
        int n = dungeon.size(), m = dungeon[0].size();
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == n - 1 and j == m - 1) {
            if(dungeon[i][j] > 0) {
                return dp[i][j] = 0;
            }
            else {
                int val = abs(dungeon[i][j]);
                return dp[i][j] = val;
            }
        }
        
        // Both right and down cell exist
        if(i + 1 < n and j + 1 < m) {
            if(dungeon[i][j] <= 0) {        // When current cell has -ve or 0 value
                return dp[i][j] = abs(dungeon[i][j]) + min(solve(dungeon, i, j+1, dp), solve(dungeon, i+1, j, dp));
            }
            else {                          // When current cell has +ve vale
                int left_point = dungeon[i][j] - min(solve(dungeon, i, j+1, dp), solve(dungeon, i+1, j, dp));
                if(left_point >= 0) {
                    return dp[i][j] = 0;
                }
                else {
                    int val = abs(left_point);
                    return dp[i][j] = val;
                }
                // return abs(min(0, dungeon[i][j] - min(solve(dungeon, i, j+1), solve(dungeon, i+1, j))));
            }
        }
        // When only right cell exist
        if(j + 1 < m) {
            if(dungeon[i][j] <= 0) {        // When current cell has -ve or 0 value
                return dp[i][j] = abs(dungeon[i][j]) + solve(dungeon, i, j+1, dp);
            }
            else {                          // When current cell has +ve vale
                int left_point = dungeon[i][j] - solve(dungeon, i, j+1, dp);
                if(left_point >= 0) {
                    return dp[i][j] = 0;
                }
                else {
                    int val = abs(left_point);
                    return dp[i][j] = val;
                }
                // return abs(min(0, dungeon[i][j] - solve(dungeon, i, j+1)));
            }
        }
        
        // When only down cell exist
        if(i + 1 < n) {
            if(dungeon[i][j] <= 0) {        // When current cell has -ve or 0 value
                return dp[i][j] = abs(dungeon[i][j]) + solve(dungeon, i+1, j, dp);
            }
            else {                          // When current cell has +ve vale
                int left_point = dungeon[i][j] - solve(dungeon, i+1, j, dp);
                if(left_point >= 0) {
                    return dp[i][j] = 0;
                }
                else {
                    int val = abs(left_point);
                    return dp[i][j] = val;
                }
                // return abs(min(0, dungeon[i][j] - solve(dungeon, i, j+1)));
            }
        }
        return 0;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // dp[i][j] --> min health required to reach dest(n-1, m-1) from (i, j)
        // ans --> dp[0][0]
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(dungeon, 0, 0, dp) + 1;
    }
};