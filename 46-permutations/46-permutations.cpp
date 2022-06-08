class Solution {
public:
    
    void solve(int idx,int n,vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp) {
        if(idx==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++) {
            swap(nums[i],nums[idx]);
            temp.push_back(nums[idx]);
            solve(idx+1,n,nums,ans,temp);
            temp.pop_back();
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        solve(0,n,nums,ans,temp);
        return ans;
    }
};