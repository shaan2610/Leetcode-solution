class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n);
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--) {
            suff[i]=max(suff[i+1],nums[i]);
        }
        int mn=nums[0];
        for(int i=1;i<n-1;i++) {
            if(nums[i]>mn and suff[i+1]>nums[i]) {
                return true;
            }
            mn=min(mn,nums[i]);
        }
        return false;
    }
};