class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],freq=0,n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==ans) {
                freq++;
            }
            else {
                freq--;
                if(freq==0) {
                    ans=nums[i];
                    freq++;
                }
            }
        }
        return ans;
    }
};