class Solution {
public:
    
    void dfs(vector<vector<int>> &image,int x,int y,int col,int chkCol) {
        int dx[] = {-1,0,0,1};
        int dy[] = {0,-1,1,0};
        
        int n=image.size(),m=image[0].size();
        
        auto isBound = [&] (int i,int j) {
            if(i>=0 and i<n and j>=0 and j<m) {
                return true;
            }
            return false;
        };
        
        image[x][y]=col;
        
        for(int dir=0;dir<4;dir++) {
            int nx=x+dx[dir],ny=y+dy[dir];
            if(isBound(nx,ny) and image[nx][ny]==chkCol) {
                dfs(image,nx,ny,col,chkCol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) {
            return image;
        }
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};