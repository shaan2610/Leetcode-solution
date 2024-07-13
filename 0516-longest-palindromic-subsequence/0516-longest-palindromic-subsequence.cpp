class Solution {
public:
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
        
        return dp[n][m];
    }
    
    int longestPalindromeSubseq(string s) {
        // LCS of s and rev(s)
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return longestCommonSubsequence(s, s_rev);
    }
};