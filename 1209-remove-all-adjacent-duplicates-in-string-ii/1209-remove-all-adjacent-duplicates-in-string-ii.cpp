class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>> st;
        int cnt=1;
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push({s[i],cnt});
                cnt++;
            }
            else {
                auto p=st.top();
                if(p.first==s[i]) {
                    st.pop();
                    st.push({s[i],p.second+1});
                    if(st.top().second==k) {
                        st.pop();
                        cnt=1;
                    }
                    else {
                        cnt++;
                    }
                }
                else {
                    cnt=1;
                    st.push({s[i],cnt});
                    cnt++;
                }
            }
        }
        string ans;
        while(not st.empty()) {
            auto p=st.top();
            st.pop();
            int cnt=p.second;
            char c=p.first;
            while(cnt--) {
                ans.push_back(c);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};