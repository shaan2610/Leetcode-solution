class Solution {
public:
    
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool dfs(int x,int y,string &word,int idx,vector<vector<char>> &board) {
        int n=board.size(),m=board[0].size(),len=word.size();
        if(idx==len) {
            return true;
        }
        if(word[idx]!=board[x][y]) {
            return false;
        }
        
        auto chkBound = [&] (int i,int j) {
            return (i>=0 and i<n and j>=0 and j<m);
        };
        
        bool ans=false;
        char org=board[x][y];
        board[x][y]='*';
        int chk=0;
        for(int dir=0;dir<4;dir++) {
            int nx=x+dx[dir],ny=y+dy[dir];
            if(chkBound(nx,ny)) {
                chk++;
                ans|=dfs(nx,ny,word,idx+1,board);
            }
        }
        board[x][y]=org;
        if(chk==0 and idx==len-1) {
            return true;
        }
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int len=word.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dfs(i,j,word,0,board)) {
                    return true;
                }
            }
        }
        return false;
    }
};