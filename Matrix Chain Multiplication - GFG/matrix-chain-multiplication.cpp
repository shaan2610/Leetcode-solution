// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        
        for(int len=1;len<=n;len++) {
            for(int l=0;l+len-1<n;l++) {
                int r=l+len-1;
                if(len<3) {
                    dp[l][r]=0;
                }
                else {
                    for(int part=l+1;part<r;part++) {
                        dp[l][r]=min(dp[l][r],dp[l][part]+dp[part][r]+arr[l]*arr[part]*arr[r]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends