class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        
        auto diff = [&] (int i,int j) {
            int dx=points[i][0]-points[j][0];
            int dy=points[i][1]-points[j][1];
            int g=__gcd(dx,dy);
            dx/=g;
            dy/=g;
            pair<int,int> p={dx,dy};
            return p;
        };
        
        for(int i=0;i<n;i++) {
            map<pair<int,int>,int> mp;
            int temp=0;
            for(int j=0;j<n;j++) {
                if(i==j) {
                    continue;
                }
                mp[diff(i,j)]++;
                temp=max(temp,mp[diff(i,j)]);
            }
            ans=max(ans,temp);
        }
        return (ans+1);
    }
};