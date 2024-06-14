class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.empty()) {
            return 0;
        }
        int left = 0, right = 0, len = 1;
        map<char, int> freq;
        while(right < n) {
            freq[s[right]]++;
            int curr_len = right - left + 1;
            while(freq.size() < curr_len) { // Repetition is taking place
                freq[s[left]]--;
                if(freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }
                left++;
                curr_len = right - left + 1;
            }
            curr_len = right - left + 1;
            if(curr_len > len) {
                len = curr_len;
            }
            right++;
        }
        return len;
    }
};