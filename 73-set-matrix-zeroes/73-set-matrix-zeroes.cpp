class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        bool row=true,col=true;
        for(int i=0;i<n;i++) {
            if(a[i][0]==0) {
                col=false;
            }
        }
        for(int j=0;j<m;j++) {
            if(a[0][j]==0) {
                row=false;
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(a[i][j]==0) {
                    a[i][0]=a[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++) {
            if(a[i][0]==0) {
                for(int j=0;j<m;j++) {
                    a[i][j]=0;
                }
            }
        }
        for(int j=1;j<m;j++) {
            if(a[0][j]==0) {
                for(int i=0;i<n;i++) {
                    a[i][j]=0;
                }
            }
        }
        if(not row) {
            for(int j=0;j<m;j++) {
                a[0][j]=0;
            }
        }
        if(not col) {
            for(int i=0;i<n;i++) {
                a[i][0]=0;
            }
        }
    }
};