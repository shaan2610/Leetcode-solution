class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1) {
            return nums;
        }
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0;i<n;i++) {
            while(dq.empty() == false and nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
//             Checking the reach
            if(dq.front() < i-k+1) {
                dq.pop_front();
            }
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};