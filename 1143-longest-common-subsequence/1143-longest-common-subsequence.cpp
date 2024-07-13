class Solution {
public:
    int solve(string &text1, int i, string &text2, int j, vector<vector<int>> &dp) {
        // i is index in first string and j is index in second string
        if(i < 0 or j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(text1, i - 1, text2, j - 1, dp);
        }
        else {
            return dp[i][j] = max(solve(text1, i - 1, text2, j, dp), solve(text1, i, text2, j - 1, dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, n - 1, text2, m - 1, dp);
    }
};