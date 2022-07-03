class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int sz=cuts.size();
        vector<vector<int>> dp(sz,vector<int>(sz,1e9));
        for(int len=1;len<=sz;len++) {
            for(int l=0;l+len-1<sz;l++) {
                int r=l+len-1;
                if(len<3) {
                    dp[l][r]=0;
                }
                else {
                    for(int part=l+1;part<r;part++) {
                        dp[l][r]=min(dp[l][r],dp[l][part]+dp[part][r]+(cuts[r]-cuts[l]));
                    }
                }
            }
        }
        return dp[0][sz-1];
    }
};