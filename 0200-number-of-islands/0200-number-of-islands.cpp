class Solution {
public:
    vector<int> dx = {-1, 0, 0, 1};
    vector<int> dy = {0, -1, 1, 0};
    
    bool is_inside(int x, int y, int n, int m) {
        if(x >= 0 and x < n and y >= 0 and y < m) {
            return true;
        }
        return false;
    }
    
    void dfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[x][y]++;
        // (x, y) --> (nx, ny)
        int n = grid.size(), m = grid[0].size();
        for(int dir=0;dir<4;dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if(is_inside(nx, ny, n, m) and grid[nx][ny] == '1' and vis[nx][ny] == 0) {
                dfs(nx, ny, vis, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int no_islands = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(vis[i][j] != 0 or grid[i][j] == '0') {     // Either it is water or the land is already visited
                    continue;
                }
                no_islands++;
                dfs(i, j, vis, grid);
            }
        }
        return no_islands;
    }
};