class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        reverse(satisfaction.begin(),satisfaction.end());
        int ans=0,sum=0,lans=0;
        for(int i=0;i<n;i++) {
            lans+=sum;
            sum+=satisfaction[i];
            lans+=satisfaction[i];
            ans=max(ans,lans);
        }
        return ans;
    }
};