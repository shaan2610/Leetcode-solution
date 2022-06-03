class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    long long val=(long long)target-nums[i]-nums[j]-nums[k];
                    int idx=lower_bound(nums.begin()+k+1,nums.end(),val)-nums.begin();
                    if(idx!=n and nums[idx]==val) {
                        vector<int> v(4);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[k];
                        v[3]=val;
                        ans.push_back(v);
                    }
                    while(k+1<n and nums[k]==nums[k+1]) {
                        k++;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1]) {
                    j++;
                }
            } 
            while(i+1<n and nums[i]==nums[i+1]) {
                i++;
            }
        }
        return ans;
    }
};