class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        
        stack<char> st;
        vector<int> last_idx(26, -1);
        for(int i=0;i<n;i++) {
            last_idx[s[i] - 'a'] = i;
        }
        
        vector<int> vis(26);
//         vis[c] = 1 --> c is present in the stack
//         vis[c] = 0 --> c is not present in the stack
        
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                st.push(s[i]);
                vis[s[i] - 'a']++;
            }
            else {
                if(vis[s[i] - 'a'] != 0) {
                    continue;
                }
                while(not st.empty() and st.top() > s[i] and last_idx[st.top() - 'a'] > i) {
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i] - 'a']++;
            }
        }
        string ans;
        while(not st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};