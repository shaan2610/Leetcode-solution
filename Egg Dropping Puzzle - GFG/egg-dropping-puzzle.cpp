// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<long long>> dp(k+1,vector<long long>(n+1));
        for(int i=0;i<=k;i++) {
            dp[i][0]=INT_MAX;
        }
        for(int j=0;j<=n;j++) {
            dp[0][j]=0;
        }
        for(int i=1;i<=k;i++) {
            for(int j=1;j<=n;j++) {
                dp[i][j]=INT_MAX;
                for(int x=1;x<=i;x++) {
                    dp[i][j]=min(dp[i][j],max(dp[x-1][j-1],dp[i-x][j])+1ll);
                }
            }
        }
        return dp[k][n];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends