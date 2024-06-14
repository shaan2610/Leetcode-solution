class Solution {
public:
//     Modify your question
//     Find count of subarrays having atmost k distinct elements
   int atmostK(vector<int> &nums, int k) {
       int n = nums.size();
       int left = 0, right = 0, ans = 0;
       unordered_map<int, int> mp;
       while(right < n) {
           mp[nums[right]]++;
           while(mp.size() > k) {
               mp[nums[left]]--;
               if(mp[nums[left]] == 0) {
                   mp.erase(nums[left]);
               }
               left++;
           }
           ans += (right - left + 1);
           right++;
       }
       return ans;
   }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (atmostK(nums, k) - atmostK(nums, k - 1));
    }
};