class Solution {
public:
    
    void solve(int idx,int n,string &s,vector<vector<string>> &ans,vector<string> &temp) {
        if(idx==n) {
            ans.push_back(temp);
            return;
        }
        auto isPalindrome = [&] (int l,int r) {
            while(l<r) {
                if(s[l]!=s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        };
        for(int i=idx;i<n;i++) {
            if(isPalindrome(idx,i)) {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,n,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        vector<string> temp;
        solve(0,n,s,ans,temp);
        return ans;
    }
};