class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        nums.push_back(1e5+5);
        for(int i=0;i<n;i++){
            int low=i+1,high=n-1,target=-nums[i];
            while(low<high) {
                if(nums[low]+nums[high]<target) {
                    low++;
                }
                else if(nums[low]+nums[high]>target) {
                    high--;
                }
                else {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                    ans.push_back(v);
                    while(low+1<high and nums[low]==nums[low+1]) {
                        low++;
                    }
                    while(high-1>low and nums[high]==nums[high-1]) {
                        high--;
                    }
                    low++;
                    high--;
                }
            }
            while(i+1<n and nums[i]==nums[i+1]) {
                i++;
            }
        }
        return ans;
    }
};