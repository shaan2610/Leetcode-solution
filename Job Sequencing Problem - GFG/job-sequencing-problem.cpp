// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static cmp (const Job &a,const Job &b) {
        return (a.profit>b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        int ans=0,profit=0;
        set<int> s;
        for(int i=1;i<=100;i++) {
            s.insert(i);
        }
        for(int i=0;i<n;i++) {
            auto it=s.upper_bound(arr[i].dead);
            if(it==s.begin()) {
                continue;
            }
            it--;
            int time=*it;
            if(time<=arr[i].dead) {
                profit+=arr[i].profit;
                ans++;
                s.erase(time);
            }
        }
        vector<int> v;
        v.push_back(ans);
        v.push_back(profit);
        return v;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends