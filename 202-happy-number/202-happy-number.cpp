class Solution {
public:
    
    bool isHappy(int n) {
        set<int> s;
        while(n!=1 and not s.count(n)) {
            s.insert(n);
            int sum=0;
            while(n) {
                int x=n%10;
                sum+=(x*x);
                n/=10;
            }
            cout<<sum;
            n=sum;
        }
        if(n==1) {
            return true;
        }
        return false;
    }
};