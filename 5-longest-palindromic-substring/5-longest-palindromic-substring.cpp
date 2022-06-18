class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int ans=0,st=0;
        for(int len=1;len<=n;len++) {
            for(int l=0;l+len-1<n;l++) {
                int r=l+len-1;
                if(len==1) {
                    dp[l][r]=1;
                }
                else if(len==2) {
                    dp[l][r]=(s[l]==s[r]);
                }
                else {
                    dp[l][r]=(dp[l+1][r-1] and s[l]==s[r]);
                }
                if(dp[l][r] and len>ans) {
                    ans=len;
                    st=l;
                }
            }
        }
        return s.substr(st,ans);
    }
};