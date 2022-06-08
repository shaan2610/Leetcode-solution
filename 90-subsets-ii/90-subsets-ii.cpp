class Solution {
public:
    
    void solve(int idx,int n,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp) {
        ans.push_back(temp);
        if(idx==n) {
            return;
        }
        for(int i=idx;i<n;i++) {
            temp.push_back(nums[i]);
            solve(i+1,n,nums,ans,temp);
            while(i+1<n and nums[i]==nums[i+1]) {
                i++;
            }
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,n,nums,ans,temp);
        return ans;
    }
};