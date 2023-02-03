//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=1,high=m;
	    auto nthPower = [&] (int x) {
	        long long ans=1ll;
	        for(int i=0;i<n;i++) {
	            ans=ans*x;
	            if(ans>m) {
	                return (m+1);
	            }
	        }
	        int fans=ans;
	        return fans;
	    };
	    
	    while(low<=high) {
	        int mid=(low+high)/2;
	        if(nthPower(mid)<=m) {
	            low=mid+1;
	        }
	        else {
	            high=mid-1;
	        }
	    }
	    if(nthPower(low-1)==m) {
	        return (low-1);
	    }
	    else {
	        return -1;
	    }
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends