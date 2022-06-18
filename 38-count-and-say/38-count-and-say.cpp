class Solution {
public:
    string countAndSay(int n) {
        if(n==1) {
            return "1";
        }
        string s=countAndSay(n-1);
        string ans;
        int cnt=1;
        int z=s.size();
        s.push_back('*');
        for(int i=0;i<z;i++) {
            if(s[i]!=s[i+1]) {
                ans+=to_string(cnt);
                ans.push_back(s[i]);
                cnt=1;
            }
            else {
                cnt++;
            }
        }
        return ans;
    }
};