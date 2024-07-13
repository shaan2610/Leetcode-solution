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
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        // dp[i][j] --> Length of LCS considering first i charaters of text1 and first j characters of text2
        // ans --> dp[n][m]
        for(int i=0;i<=n;i++) {
            dp[i][0] = 0;
        }
        for(int i=0;i<=m;i++) {
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                // ==> We are at (i-1)th index on text1 and (j-1)th index at text2
                // We are considering first i characters of text1 and first j characters of text2
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i = n, j = m;
        string lcs;
        while(i > 0 and j > 0) {
            if(text1[i-1] == text2[j-1]) {      // Value must have came from upper left diagonal
                lcs.push_back(text1[i-1]);
                i--;
                j--;
            }
            else {      // Value must be one of the max of left or top
                if(dp[i][j] == dp[i][j-1]) {        // Value came from left
                    j--;
                }
                else {      // Value came from top
                    i--;
                }
            }
        }
        
        reverse(lcs.begin(), lcs.end());
        cout<<lcs;
        
        return lcs.size();
    }
};