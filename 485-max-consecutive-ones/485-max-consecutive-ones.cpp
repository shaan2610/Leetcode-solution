class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int ans=0,cnt=0,n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]) {
                cnt++;
            }
            else {
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ans;
    }
};