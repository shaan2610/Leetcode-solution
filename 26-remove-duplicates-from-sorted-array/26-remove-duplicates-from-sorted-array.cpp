class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx=0,n=nums.size();
        for(int i=0;i<n;i++) {
            while(i+1<n and nums[i]==nums[i+1]) {
                i++;
            }
            nums[idx++]=nums[i];
        }
        return idx;
    }
};