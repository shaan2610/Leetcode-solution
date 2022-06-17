class Solution {
public:
    
    class Node {
    public:
        int x,y,time;
        Node(int i,int j,int t) {
            x=i;
            y=j;
            time=t;
        }
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        auto chkBound = [&] (int x,int y) {
            if(x>=0 and x<n and y>=0 and y<m) {
                return true;
            }
            return false;
        };
        
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        
        queue<Node*> q;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2) {
                    Node* newNode = new Node(i,j,0);
                    q.push(newNode);
                }
            }
        }
        int ans=0;
        while(not q.empty()) {
            Node* node=q.front();
            q.pop();
            int x=node->x,y=node->y,time=node->time;
            for(int dir=0;dir<4;dir++) {
                int nx=x+dx[dir],ny=y+dy[dir];
                if(chkBound(nx,ny) and grid[nx][ny]==1) {
                    grid[nx][ny]=2;
                    Node* newNode = new Node(nx,ny,time+1);
                    ans=max(ans,time+1);
                    q.push(newNode);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};