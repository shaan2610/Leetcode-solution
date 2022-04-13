class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int dx[] = {-1,-1,-1,0,0,1,1,1};
        int dy[] = {-1,0,1,-1,1,-1,0,1};
        vector<vector<int>> ans(n,vector<int>(m));
        
        auto chk = [&] (int x,int y) {
            if(x<n and y<m and x>=0 and y>=0) {
                return true;
            }  
            return false;
        };
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int cnt=0;
                for(int k=0;k<8;k++) {
                    if(chk(i+dx[k],j+dy[k])) {
                        cnt+=a[i+dx[k]][j+dy[k]];
                    }
                }
                if(cnt<2) {
                    ans[i][j]=0;
                }
                else if(cnt==3) {
                    ans[i][j]=1;
                }
                else if(cnt==2) {
                    ans[i][j]=a[i][j];
                }
                else if(cnt>3) {
                    ans[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                a[i][j]=ans[i][j];
            }
        }
    }
};