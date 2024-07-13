class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j] = true if substring s[i..j] is a palindrome
        // dp[i][j] = false otherwise
        // ans --> (check all the substring, if dp[i][j] == true, then maximise the length)
        // if(i == j) ==> len = 1 ==> dp[i][j] = 1
        vector<vector<bool>> dp(n, vector<bool>(n));
        int st = -1, max_len = 0;
        for(int len=1;len<=n;len++) {
            for(int start=0;start<n;start++) {
                int end = start + len - 1;
                if(end >= n) {      // Invalid index
                    continue;
                }
                if(len == 1) {
                    dp[start][end] = true;
                }
                else if(len == 2) {
                    if(s[start] == s[end]) {
                        dp[start][end] = true;
                    }
                    else {
                        dp[start][end] = false;
                    }
                }
                else {
                    if(s[start] == s[end]) {
                        dp[start][end] = dp[start+1][end-1];
                    }
                    else {
                        dp[start][end] = false;
                    }
                }
                if(dp[start][end] == true) {
                    if(len > max_len) {
                        max_len = len;
                        st = start;
                    }
                }
            }
        }
        return s.substr(st, max_len);
    }
};