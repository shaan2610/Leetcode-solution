class Solution {
public:
    
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans) {
        
        if(col==n) {
            ans.push_back(board);
            return;
        }
        
        auto chkBound = [&] (int x,int y) {
            if(x>=0 and x<n and y>=0 and y<n) {
                return true;
            }
            return false;
        };
        
        auto isPossible = [&] (int r) {
            int c=col;
            int dx[] = {-1,-1,-1,0,0,1,1,1};
            int dy[] = {-1,0,1,-1,1,-1,0,1};
            for(int dir=0;dir<8;dir++) {
                int x=r+dx[dir],y=c+dy[dir];
                while(chkBound(x,y)) {
                    if(board[x][y]=='Q') {
                        return false;
                    }
                    x+=dx[dir];
                    y+=dy[dir];
                }
            }
            return true;
        };
        
        for(int row=0;row<n;row++) {
            if(isPossible(row)) {
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i=0;i<n;i++) {
            s.push_back('.');
        }
        vector<string> board(n,s);
        vector<vector<string>> ans;
        solve(0,n,board,ans);
        return ans;
    }
};