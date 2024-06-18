class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size(), ans = 0;
        unordered_map<int, bool> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]] = false;
        }
        for(int i=0;i<n;i++) {
//             Mark all the starting points
            if(mp.count(nums[i] - 1)) { // It is not a starting point
                mp[nums[i]] = true;
            }
        }
        for(int i=0;i<n;i++) {
            if(mp[nums[i]] == false) {      // Starting point
                int curr_len = 1;
                while(mp.count(nums[i] + curr_len)) {
                    curr_len++;
                }
                ans = max(ans, curr_len);
            }
        }
        return ans;
    }
};