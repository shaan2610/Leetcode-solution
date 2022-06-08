// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool solve(int node,vector<vector<int>> &adj,int m,int n,vector<int> &col) {
    
    if(node==n) {
        return true;
    }
    
    auto isPossible = [&] (int c) {
        for(auto i:adj[node]) {
            if(col[i]==c) {
                return false;
            }
        }
        return true;
    };
    
    for(int i=1;i<=m;i++) {
        if(isPossible(i)) {
            col[node]=i;
            if(solve(node+1,adj,m,n,col)) {
                return true;
            }
            col[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<vector<int>> adj(n);
    vector<int> col(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(graph[i][j] and i!=j) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    return solve(0,adj,m,n,col);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends