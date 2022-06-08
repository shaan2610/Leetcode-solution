class Solution {
public:
    
    void solve(int idx,int n,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &temp,int target,int sum) {
        if(sum>target) {
            return;
        }
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        if(idx==n) {
            return;
        }
        for(int i=idx;i<n;i++) {
            if(sum+candidates[i]<=target) {
                temp.push_back(candidates[i]);
                solve(i,n,candidates,ans,temp,target,sum+candidates[i]);
                temp.pop_back();
            }
            else {
                break;
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n=candidates.size();
        solve(0,n,candidates,ans,temp,target,0);
        return ans;
    }
};