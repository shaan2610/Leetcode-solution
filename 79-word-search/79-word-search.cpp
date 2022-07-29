class Solution {
public:
    
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool dfs(int x,int y,vector<vector<int>> &vis,string &word,int idx,vector<vector<char>> &board) {
        int n=vis.size(),m=vis[0].size(),len=word.size();
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
        vis[x][y]++;
        int chk=0;
        for(int dir=0;dir<4;dir++) {
            int nx=x+dx[dir],ny=y+dy[dir];
            if(chkBound(nx,ny) and not vis[nx][ny]) {
                chk++;
                ans|=dfs(nx,ny,vis,word,idx+1,board);
            }
        }
        vis[x][y]=0;
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
                vector<vector<int>> vis(n,vector<int>(m));
                if(dfs(i,j,vis,word,0,board)) {
                    return true;
                }
            }
        }
        return false;
    }
};