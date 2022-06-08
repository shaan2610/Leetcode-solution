// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(int x,int y,int n,vector<vector<int>> &a,vector<string> &ans,string &temp,vector<vector<int>> &vis) {
        if(x==n-1 and y==n-1) {
            ans.push_back(temp);
            return;
        }
        
        auto chkBound = [&] (int r,int c) {
            if(r>=0 and r<n and c>=0 and c<n) {
                return true;
            }
            return false;
        };
        
        auto isPossible = [&] (int x,int y) {
            if(a[x][y] and vis[x][y]==0) {
                return true;
            }
            return false;
        };
        
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        char dr[] = {'U','L','R','D'};
        vis[x][y]=1;
        for(int dir=0;dir<4;dir++) {
            int nx=x+dx[dir],ny=y+dy[dir];
            if(chkBound(nx,ny)) {
                if(isPossible(nx,ny)) {
                    temp.push_back(dr[dir]);
                    solve(nx,ny,n,a,ans,temp,vis);
                    temp.pop_back();
                }
            }
        }
        vis[x][y]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &a, int n) {
        // Your code goes here
        vector<string> ans;
        string temp;
        if(a[0][0]==0) {
            return ans;
        }
        vector<vector<int>> vis(n,vector<int>(n));
        solve(0,0,n,a,ans,temp,vis);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends