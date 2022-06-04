class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> freq(256);
        int i=0,j=0,ans=0,n=s.size();
        while(j<n and i<=j) {
            if(freq[s[j]]==0) {
                freq[s[j]]++;
                j++;
            }
            else {
                while(freq[s[j]]) {
                    freq[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};