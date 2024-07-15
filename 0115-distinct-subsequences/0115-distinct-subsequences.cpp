class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // dp[i][j] --> no of distinct subsequences in substring s[0...i] which is equal to t[0..j]
        // ans --> dp[n-1][m-1]
        vector<vector<long long>> dp(n, vector<long long>(m));
        
        // Base Case
        if(s[0] == t[0]) {
            dp[0][0] = 1ll;
        }
        else {
            dp[0][0] = 0ll;
        }
        
        // dp[0][i] = 0 for all i from i to m-1
        // string s is of len 1 and string t is of len greater than 1
        // So we can't make a subsequence of len greater than 1 from a string of len 1
        // s -> "a", t -> "ab"
        for(int i=1;i<m;i++) {
            dp[0][i] = 0ll;
        }
        
        // dp[i][0] = no of character t[0] in the substring s[0..i]
        long long cnt_t0 = 0ll;
        for(int i=0;i<n;i++) {
            if(s[i] == t[0]) {
                cnt_t0++;
            }
            dp[i][0] = cnt_t0;
        }
        
        int mod = 1e9 + 7;
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
                dp[i][j] %= mod;
            }
        }
        return dp[n-1][m-1];
    }
};