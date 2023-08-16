//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> dist(31, 1e9);
        dist[1] = 0;
        while(not q.empty()) {
            int cell = q.front().first, moves = q.front().second;
            q.pop();
            for(int dx=1;dx<=6;dx++) {
                int new_cell = cell + dx;
                if(new_cell > 30) {
                    continue;
                }
                bool normal_cell = true;
                for(int i=0;i<n;i++) {
                    if(arr[2*i] == new_cell) {
                        normal_cell = false;
                        if(dist[arr[(2 * i) + 1]] > moves + 1) {
                            dist[arr[(2 * i) + 1]] = moves + 1;
                            q.push({arr[(2 * i) + 1], moves + 1});
                        }
                        break;
                    }
                }
                if(normal_cell) {
                    if(dist[new_cell] > moves + 1) {
                        dist[new_cell] = moves + 1;
                        q.push({new_cell, moves + 1});
                    }
                }
            }
        }
        return dist[30];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends