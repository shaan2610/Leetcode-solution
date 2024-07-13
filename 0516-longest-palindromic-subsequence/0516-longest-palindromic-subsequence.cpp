class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // dp[i][j] = length of LPS of substring s[i..j]
        // ans --> dp[0][n-1]
        // if(i == j) ==> len = 1 ==> dp[i][j] = 1
        vector<vector<int>> dp(n, vector<int>(n));
        for(int len=1;len<=n;len++) {
            for(int start=0;start<n;start++) {
                int end = start + len - 1;
                if(end >= n) {      // Invalid index
                    continue;
                }
                if(len == 1) {
                    dp[start][end] = 1;
                }
                else if(len == 2) {
                    if(s[start] == s[end]) {
                        dp[start][end] = 2;
                    }
                    else {
                        dp[start][end] = 1;
                    }
                }
                else {
                    if(s[start] == s[end]) {
                        dp[start][end] = 2 + dp[start+1][end-1];
                    }
                    else {
                        dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};