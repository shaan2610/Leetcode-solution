class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26);
        int n=s.size();
        if(t.size()!=n) {
            return false;
        }
        for(int i=0;i<n;i++) {
            cnt[s[i]-'a']++;
            cnt[t[i]-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(cnt[i]) {
                return false;
            }
        }
        return true;
    }
};