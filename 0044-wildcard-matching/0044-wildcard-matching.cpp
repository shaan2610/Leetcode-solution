class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // dp[i][j] = whether we can match s[prefix of len i] with p[prefix of length j]
        // ans --> dp[n][m]
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        // Base case
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++) {
            dp[i][0] = 0;
        }
        
        bool can_match = true;
        for(int i=1;i<=m;i++) {
            if(p[i-1] != '*') {       // Once it become false it will never be true again
                can_match = false;
            }
            if(can_match == true) {     // Considering all the prefixes which contains only * characters
                dp[0][i] = 1;
            }
            else {
                dp[0][i] = 0;
            }
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = 0;
                if(s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[j-1] == '?') {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1] == '*') {
                        // dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-2][j-1] || ... || dp[0][j-1];
                        for(int k=0;k<=i;k++) {
                            dp[i][j] |= dp[k][j-1];
                        }
                    }
                    else {      // p[j-1] is a lowercase english character which is not matching with s[i-1]
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[n][m];
    }
};