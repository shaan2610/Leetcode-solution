// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		
	const int N=1e5+5;	
		
	class segtree {
	public:
	    vector<int> t;
	    int n;
	    segtree(int sz) {
	        n=sz;
	        t.resize(4*n+5);
	    }
	    
	    void update(int st,int en,int v,int idx,int val) {
	        if(st>en or idx>en or idx<st) {
	            return;
	        }
	        if(st==en) {
	            t[v]=val;
	            return;
	        }
	        int mid=(st+en)/2;
	        update(st,mid,2*v,idx,val);
	        update(mid+1,en,2*v+1,idx,val);
	        t[v]=max(t[2*v],t[2*v+1]);
	    }
	    
	    void update(int idx,int val) {
	        update(0,n-1,1,idx,val);
	    }
	    
	    int getMax(int st,int en,int v,int l,int r) {
	        if(st>en or l>r or r<st or l>en) {
	            return 0;
	        }
	        if(st>=l and en<=r) {
	            return t[v];
	        }
	        int mid=(st+en)/2;
	        return max(getMax(st,mid,2*v,l,r),getMax(mid+1,en,2*v+1,l,r));
	    }
	    
	    int getMax(int l,int r) {
	        return getMax(0,n-1,1,l,r);
	    }
	    
	};

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    segtree st(N);
	    int ans=0;
	    for(int i=0;i<n;i++) {
	        int val=arr[i]+st.getMax(0,arr[i]-1);
	        ans=max(ans,val);
	        st.update(arr[i],max(val,st.getMax(arr[i],arr[i])));
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends