class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(mid+1<n and nums[mid]==nums[mid+1]) {
                if(mid&1) {
                    high=mid-1;
                }
                else {
                    low=mid+1;
                }
            }
            else if(mid-1>=0 and nums[mid]==nums[mid-1]) {
                if(mid&1) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            else {
                return nums[mid];
            }
        }
        return (nums[high+1]);
    }
};