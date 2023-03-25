//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long mergeCount(long long arr[],int low,int mid,int high) {
        int ptr1=low,end1=mid;
        int ptr2=mid+1,end2=high;
        int tempSize=high-low+1;
        int index=0;
        long long temp[tempSize];
        long long count=0;
        while(ptr1<=end1 and ptr2<=end2) {
            if(arr[ptr1]<=arr[ptr2]) {
                temp[index]=arr[ptr1];
                ptr1++;
                index++;
            }
            else {
                count+=(end1-ptr1+1);
                temp[index]=arr[ptr2];
                ptr2++;
                index++;
            }
        }
        while(ptr1<=end1) {
            temp[index]=arr[ptr1];
            ptr1++;
            index++;
        }
        while(ptr2<=end2) {
            temp[index]=arr[ptr2];
            ptr2++;
            index++;
        }
        for(int i=0;i<tempSize;i++) {
            arr[low+i]=temp[i];
        }
        return count;
    }
    
    long long countInversionUsingMergeSort(long long arr[],int low,int high) {
        if(low==high) {
            return 0;
        }
        int mid=(low+high)/2;
        long long ans=0;
        ans+=countInversionUsingMergeSort(arr,low,mid);
        ans+=countInversionUsingMergeSort(arr,mid+1,high);
        ans+=mergeCount(arr,low,mid,high);
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