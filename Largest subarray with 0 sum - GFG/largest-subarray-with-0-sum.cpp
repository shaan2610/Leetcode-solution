// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        vector<int> pref(n+1);
        map<int,int> m;
        for(int i=0;i<n;i++) {
            pref[i+1]=pref[i]+a[i];
            m[pref[i+1]]=i+1;
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            ans=max(ans,m[pref[i]]-i);
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends