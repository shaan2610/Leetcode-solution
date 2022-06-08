class Solution {
public:
    
    bool solve(int idx,vector<vector<char>> &board) {
        int row=idx/9,col=idx%9;
        if(row==9) {
            return true;
        }
        if(board[row][col]!='.') {
            return solve(idx+1,board);
        }
        
        auto isPossible = [&] (char c) {
            for(int i=0;i<9;i++) {
                if(board[i][col]==c or board[row][i]==c) {
                    return false;
                }
            }
            int upperRow=(row/3)*3,upperCol=(col/3)*3;
            for(int i=upperRow;i<upperRow+3;i++) {
                for(int j=upperCol;j<upperCol+3;j++) {
                    if(board[i][j]==c) {
                        return false;
                    }
                }
            }
            return true;
        };
        
        bool flag=false;
        for(char c='1';c<='9';c++) {
            if(isPossible(c)) {
                board[row][col]=c;
                if(solve(idx+1,board)) {
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,board);
    }
};