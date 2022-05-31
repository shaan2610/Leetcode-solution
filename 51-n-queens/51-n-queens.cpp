class Solution {
public:
    bool ispossible(int row,int col,vector<string> &board) {
        int n=board.size();
        for(int i=0;i<n;i++) {
            if(board[i][col]=='Q') {
                return false;
            }
        }
        for(int j=0;j<n;j++) {
            if(board[row][j]=='Q') {
                return false;
            }
        }
        
        auto chkbound = [&] (int x,int y) {
            if(x>=0 and x<n and y>=0 and y<n) {
                return true;
            }
            return false;
        };
        
        int dx[] = {1,1,-1,-1};
        int dy[] = {1,-1,1,-1};
        for(int dir=0;dir<4;dir++) {
            int x=row+dx[dir],y=col+dy[dir];
            while(chkbound(x,y)) {
                if(board[x][y]=='Q') {
                    return false;
                }
                x+=dx[dir];
                y+=dy[dir];
            }
        }
        return true;
    } 
    
    void helper(int col,vector<string> &board,vector<vector<string>> &ans) {
        int n=board.size();
        if(col==n) {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++) {
            if(ispossible(row,col,board)) {
                board[row][col]='Q';
                helper(col+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s;
        for(int i=0;i<n;i++) {
            s.push_back('.');
        }
        vector<string> board(n,s);
        helper(0,board,ans);
        return ans;
    }
};