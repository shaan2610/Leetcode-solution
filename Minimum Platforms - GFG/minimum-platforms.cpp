// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> numOfTrains(2400);
    	for(int i=0;i<n;i++) {
    	    numOfTrains[arr[i]]++;
    	}
    	for(int i=0;i<n;i++) {
    	    numOfTrains[dep[i]+1]--;
    	}
    	int ans=numOfTrains[0];
    	for(int i=1;i<2400;i++) {
    	    numOfTrains[i]+=numOfTrains[i-1];
    	    ans=max(ans,numOfTrains[i]);
    	}
    	return ans;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends