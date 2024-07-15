class Solution {
public:
    bool isMatch(string s, string p) {
        // dp[i][j] = whether we can match s[prefix of len i] with p[prefix of length j]
        // ans --> dp[n][m]
        
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        // Base case
        dp[0][0] = 1;
        for(int i=1;i<=n;i++) {
            dp[i][0] = 0;
        }
        for(int i=1;i<=m;i++) {
            if(p[i-1] == '*') {
                dp[0][i] = dp[0][i-2];
            }
            else {
                dp[0][i] = 0;
            }
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                dp[i][j] = 0;
                if(s[i-1] == p[j-1]) {  //  Last character matches and both are english alphabetical characters
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if(p[j-1] == '.') { // We will match . with the last character of s
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[j-1] == '*') {
                        // where * will delete its preceding character also
                        dp[i][j] = dp[i][j-2];
                        if(s[i-1] == p[j-2]) {      // Preceding character of * is matching with last character of s
                            dp[i][j] |= dp[i-1][j];
                        }
                        else if(p[j-2] == '.') {    // When preceding character of * is a .
                            dp[i][j] |= dp[i-1][j];
                        }
                        else {      // Last character of s is not matching with preceding character of * 
                                    // also preceding element will be a lowercase english character
                            dp[i][j] |= 0;
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