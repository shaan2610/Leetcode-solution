class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        int prev=nums[0];
        int lastPrev=0;
        int ans=prev;
        for(int i=2;i<=n;i++) {
            ans=max(prev,nums[i-1]+lastPrev);
            lastPrev=prev;
            prev=ans;
        }
        return ans;
    }
};