class Solution {
public:
    string getPermutation(int n, int k) {
        set<int> s;
        for(int i=1;i<=n;i++) {
            s.insert(i);
        }
        vector<int> fac(n);
        fac[0]=1;
        for(int i=1;i<n;i++) {
            fac[i]=fac[i-1]*i;
        }
        int num=n-1;
        string ans;
        while(k>1) {
            auto it=s.begin();
            while(k>fac[num]) {
                it++;
                k-=fac[num];
            }
            num--;
            ans+=to_string(*it);
            s.erase(it);
        }
        while(not s.empty()) {
            ans+=to_string(*s.begin());
            s.erase(s.begin());
        }
        return ans;
    }
};