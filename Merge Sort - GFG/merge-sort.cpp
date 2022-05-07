// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int a[], int l, int mid, int r)
    {
         // Your code here
    //     int x[m-l+1],y[r-m];
    // 	for(int i=0;i<m-l+1;i++)
    //     	x[i]=a[l+i];
    // 	for(int i=0;i<r-m;i++)
    //     	y[i]=a[m+i+1];
    // 	int i=0,j=0,k=l;
    // 	while(i<m-l+1 && j<r-m)
    // 	{
    // 		if(x[i]<=y[j])
    // 		{
    // 			a[k]=x[i];
    // 			i++;
    // 		}
    // 		else
    // 		{
    // 			a[k]=y[j];
    // 			j++;
    // 		}
    // 		k++;
    // 	}
    // 	while(i<m-l+1)
    // 	{
    // 		a[k]=x[i];
    // 		i++;
    // 		k++;
    // 	}
    // 	while(j<r-m)
    // 	{
    // 		a[k]=y[j];
    // 		j++;
    // 		k++;
    // 	}
        vector<int> v;
        for(int i=l;i<=r;i++) {
            v.push_back(a[i]);
        }
        int idx=l;
        int st1=0,st2=mid-l+1;
        while(st1<mid-l+1 and st2<r-l+1) {
            if(v[st1]<=v[st2]) {
                a[idx]=v[st1];
                st1++;
            }
            else {
                a[idx]=v[st2];
                st2++;
            }
            idx++;
        }
        while(st1<mid-l+1) {
            a[idx]=v[st1];
            st1++;
            idx++;
        }
        while(st2<r-l+1) {
            a[idx]=v[st2];
            st2++;
            idx++;
        }
    }
    public:
    void mergeSort(int a[], int l, int r)
    {
        //code here
        if(l==r) {
            return;
        }
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends