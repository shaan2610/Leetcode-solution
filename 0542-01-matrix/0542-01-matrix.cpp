class Solution {
public:
    bool is_inside(int x, int y, int n, int m) {
        return (x >= 0 and x < n and y >= 0 and y < m);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        // <x, y> of node
        vector<vector<int>> distance(n, vector<int>(m)), vis(n, vector<int>(m));
        int dist = 0;
        
        // Push all the sources
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 0) {        // Source
                    q.push({i, j});
                    vis[i][j]++;
                }
            }
        }
        
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        
        while(not q.empty()) {
            int curr_sz = q.size();
            for(int i=0;i<curr_sz;i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                int curr_dist = dist;
                distance[x][y] = curr_dist;
                for(int dir=0;dir<4;dir++) {
                    // (x, y) --> (nx, ny)
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if(is_inside(nx, ny, n, m) == false) {
                        continue;
                    }
                    if(vis[nx][ny] != 0) {      // Already visited
                        continue;
                    }
                    q.push({nx, ny});
                    vis[nx][ny]++;
                }
            }
            dist++;
        }
        return distance;
    }
};