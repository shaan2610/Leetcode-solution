// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        set<pair<int,int>> st;
        int n=str.size();
        for(int i=0;i<n;i++) {
            int j=0;
            while(i-j>=0 and i+j<n and str[i-j]==str[i+j]) {
                st.insert({i-j,i+j});
                j++;
            }
        }
        for(int i=0;i<n-1;i++) {
            int i1=i,i2=i+1,j=0;
            while(i1-j>=0 and i2+j<n and str[i1-j]==str[i2+j]) {
                st.insert({i1-j,i2+j});
                j++;
            }
        }
        vector<int> dp(n,1e9);
        for(int i=0;i<n;i++) {
            if(st.count({0,i})) {
                dp[i]=0;
            }
            else {
                for(int j=0;j<i;j++) {
                    if(st.count({j+1,i})) {
                        dp[i]=min(dp[i],dp[j]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends