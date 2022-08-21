class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        int mod=1e9+7;
        for(int i = 0; i < n; i++){
            int psum = 0;
            for(int j = i; j < n; j++){
                psum += nums[j];
                ans.push_back(psum);
            }
        }
        sort(ans.begin(), ans.end());
        int res_sum = 0;
        for(int i = left - 1; i < right; i++){
            res_sum =  (res_sum +  ans[i]) % mod;
        }
        return res_sum;
    }
};