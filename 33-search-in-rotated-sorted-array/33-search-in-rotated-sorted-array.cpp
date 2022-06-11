class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(nums[mid]>nums[n-1]) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        int pivot=high+1;
        low=0;
        high=pivot-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(nums[mid]<=target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        if(low-1>=0 and low-1<n and nums[low-1]==target) {
            return (low-1);
        }
        low=pivot;
        high=n-1;
        while(low<=high) {
            int mid=(low+high)/2;
            if(nums[mid]<=target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        if(low-1>=0 and low-1<n and nums[low-1]==target) {
            return (low-1);
        }
        return -1;
    }
};