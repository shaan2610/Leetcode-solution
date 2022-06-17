class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> q;
        for(int i=0;i<n;i++) {
            if(q.empty()) {
                q.push_back(i);
            }
            else {
                while(not q.empty() and nums[q.back()]<=nums[i]) {
                    q.pop_back();
                }
                q.push_back(i);
            }
            if(i>=k-1) {
                ans.push_back(nums[q.front()]);
            }
            if(q.front()==i-k+1) {
                q.pop_front();
            }
        }
        return ans;
    }
};