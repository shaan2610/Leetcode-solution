class Solution {
public:
    
    int oddEvenJumps(vector<int>& a) {
        int n=a.size();
        vector<vector<bool>> dp(n,vector<bool>(2));
        dp[n-1][0]=true;
        dp[n-1][1]=true;
        set<int> s;
        map<int,int> mp;
        s.insert(a[n-1]);
        mp[a[n-1]]=n-1;
        for(int i=n-2;i>=0;i--) {
            auto it=s.lower_bound(a[i]);
//             For dp[i][1]
            if(it==s.end()) {
                dp[i][1]=false;
            }
            else {
                int p=*it;
                dp[i][1]=dp[mp[p]][0];
            }
//             For dp[i][0]
            auto it1=s.upper_bound(a[i]);
            if(it1==s.begin()) {
                dp[i][0]=false;
            }
            else {
                it1--;
                int p=*it1;
                dp[i][0]=dp[mp[p]][1];
            }
            s.insert(a[i]);
            if(mp.count(a[i])) {
                mp[a[i]]=min(mp[a[i]],i);
            }
            else {
                mp[a[i]]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(dp[i][1]) {
                ans++;
            }
        }
        return ans;
    }
};