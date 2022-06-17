class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int ans=0,sum=0,lans=0;
        for(int i=n-1;i>=0;i--) {
            sum+=satisfaction[i];
            lans+=sum;
            ans=max(ans,lans);
        }
        return ans;
    }
};