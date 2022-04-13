class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int rotx[] = {0,1,0,-1};
        int roty[] = {1,0,-1,0};
        int ln=0,hn=n-1,lm=0,hm=n-1;
        auto chk = [&] (int x,int y) {
            if(x>=ln and x<=hn and y>=lm and y<=hm) {
                return true;
            }
            return false;
        };
        int idx=0,cnt=0,x=0,y=0;
        while(cnt<n*n) {
            if(chk(x,y)) {
                ans[x][y]=cnt+1;
                cnt++;
                x+=rotx[idx];
                y+=roty[idx];
            }
            else {
                if(idx==0) {
                    ln++;
                }
                else if(idx==1) {
                    hm--;
                }
                else if(idx==2) {
                    hn--;
                }
                else {
                    lm++;
                }
                x-=rotx[idx];
                y-=roty[idx];
                idx++;
                idx%=4;
                x+=rotx[idx];
                y+=roty[idx];
                ans[x][y]=cnt+1;
                cnt++;
                x+=rotx[idx];
                y+=roty[idx];
            }
        }
        return ans;
    }
};