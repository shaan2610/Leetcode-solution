class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        vector<string> v;
        string temp;
        for(auto i:s) {
            if(i==' ') {
                if(not temp.empty()) {
                    v.push_back(temp);
                    temp.clear();
                }
            }
            else {
                temp.push_back(i);
            }
        }
        reverse(v.begin(),v.end());
        string ans;
        for(auto i:v) {
            ans+=i;
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};