// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m) {
            return kthElement(arr2,arr1,m,n,k);
        }
        int low=0,high=n;
        while(low<=high) {
            int mid=(low+high)/2;
            int z=k-mid;
            if(z>=0 and z<=m) {
                int l1=(mid ? arr1[mid-1]:INT_MIN);
                int r1=(mid==n ? INT_MAX:arr1[mid]);
                int l2=(z ? arr2[z-1]:INT_MIN);
                int r2=(z==m ? INT_MAX:arr2[z]);
                if(l1<=r2 and l2<=r1) {
                    return max(l1,l2);
                }
                else if(l1>r2) {
                    high=mid-1;
                }
                else {
                    low=mid+1;   
                }
            }
            else if(z<0) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends