class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) {
            x=1.0/x;
            n=abs(n);
        }
        if(n==0) {
            return 1.0;
        }
        if(n&1) {
            return x*myPow(x,n-1);
        }
        else {
            return myPow(x*x,n/2);
        }
    }
};