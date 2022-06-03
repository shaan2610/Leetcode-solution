class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        int x=min(m,n),num=m+n;;
        double ans=1.0;
        for(int i=1;i<=x;i++) {
            ans=ans*num/i;
            num--;
        }
        return int(ans);
    }
};