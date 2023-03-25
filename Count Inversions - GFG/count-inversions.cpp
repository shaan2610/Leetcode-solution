//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long mergeCount(long long arr[],int l,int mid,int r) {
        int st1=l,en1=mid,st2=mid+1,en2=r;
        long long temp[r-l+1];
        int idx=0;
        long long count=0;
        while(st1<=en1 and st2<=en2) {
            if(arr[st1]<=arr[st2]) {
                temp[idx]=arr[st1];
                st1++;
                idx++;
            }
            else {
                count+=(en1-st1+1);
                temp[idx]=arr[st2];
                st2++;
                idx++;
            }
        }
        while(st1<=en1) {
            temp[idx]=arr[st1];
            st1++;
            idx++;
        }
        while(st2<=en2) {
            temp[idx]=arr[st2];
            st2++;
            idx++;
        }
        for(int i=0;i<r-l+1;i++) {
            arr[l+i]=temp[i];
        }
        return count;
    }
    
    long long countInversionUsingMergeSort(long long arr[],int l,int r) {
        if(l==r) {
            return 0;
        }
        long long ans=0;
        int mid=(l+r)/2;
        ans+=countInversionUsingMergeSort(arr,l,mid);
        ans+=countInversionUsingMergeSort(arr,mid+1,r);
        ans+=mergeCount(arr,l,mid,r);
        return ans;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return countInversionUsingMergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends