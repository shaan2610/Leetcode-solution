class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        auto squareSwap = [&] (int &a,int &b,int &c,int &d) {
            int temp=d;
            d=c;
            c=b;
            b=a;
            a=temp;
        };
        int x1=0,y1=0,x2=0,y2=n-1,x3=n-1,y3=n-1,x4=n-1,y4=0;
        for(int i=0;i<n/2;i++) {
            for(int j=0;j<n-1-2*i;j++) {
                squareSwap(a[x1][y1],a[x2][y2],a[x3][y3],a[x4][y4]);
                y1++;
                x2++;
                y3--;
                x4--;
            }
            int x=x1,y=y1;
            x1=x4;
            y1=y4;
            x4=x3;
            y4=y3;
            x3=x2;
            y3=y2;
            x2=x;
            y2=y;
            x1++;
            y1++;
            x2++;
            y2--;
            x3--;
            y3--;
            x4--;
            y4++;
        }
    }
};