class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size(),m=strs[0].size();
        for(int j=0;j<m;j++) {
            char c=strs[0][j];
            for(int i=0;i<n;i++) {
                if(strs[i].size()<=j) {
                    return ans;
                }
                if(c!=strs[i][j]) {
                    return ans;
                }
            }
            ans.push_back(c);
        }
        return ans;
    }
};