class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=0,cnt=1,n=nums.size();
        for(int i=0;i<n-1;i++) {
            while(i+1<n and nums[i+1]==nums[i]) {
                i++;
            }
            if(i+1<n and nums[i]!=nums[i+1]-1) {
                ans=max(ans,cnt);
                cnt=1;
            }
            else if(i+1<n and nums[i]==nums[i+1]-1) {
                cnt++;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};