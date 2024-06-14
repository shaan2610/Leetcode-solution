class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> freq_s(128), freq_t(128);
        int distinct_t = 0;   // No of distinct characters in t
        for(int i=0;i<m;i++) {
            if(freq_t[t[i]] == 0) {
                distinct_t++;
            }
            freq_t[t[i]]++;
        }
        int l = 0, distinct_s = 0, r;
        for(int i=0;i<n;i++) {
            freq_s[s[i]]++;
            if(freq_s[s[i]] == freq_t[s[i]]) {
                distinct_s++;
            }
            if(distinct_s == distinct_t) {
                r = i;
                break;
            }
        }
        if(distinct_s != distinct_t) {
            return "";
        }
        int left_idx = l, right_idx = r, len = r - l + 1;
        while(r < n) {
//             Cond to move left pointer is that freq_s[s[left]] > freq_t[s[left]]
            while(freq_s[s[l]] > freq_t[s[l]]) {
                freq_s[s[l]]--;
                l++;
            }
            int curr_len = r - l + 1;
            if(curr_len < len) {
                len = curr_len;
                left_idx = l;
                right_idx = r;
            }
            r++;
            if(r < n) {
                freq_s[s[r]]++;
            }
        }
        return s.substr(left_idx, len);
    }
};