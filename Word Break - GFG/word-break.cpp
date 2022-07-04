// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string a, vector<string> &b) {
        //code here
        int n=b.size(),m=a.size();
        vector<int> dp(m+1);
        set<string> st;
        for(auto i:b) {
            st.insert(i);
        }
        dp[0]=1;
        for(int i=1;i<=m;i++) {
            for(int len=1;len<=i;len++) {
                if(dp[i-len] and st.count(a.substr(i-len,len))) {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[m];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends