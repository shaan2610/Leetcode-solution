class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> m;
        for(int i=0;i<k;i++) {
            m.insert(nums[i]);
        }
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i+k-1<n;i++) {
            ans.push_back(*m.begin());
            m.erase(m.find(nums[i]));
            if(i+k<n) {
                m.insert(nums[i+k]);
            }
        }
        return ans;
    }
};