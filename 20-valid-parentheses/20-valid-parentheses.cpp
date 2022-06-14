class Solution {
public:
    bool isValid(string s) {
        
        auto close = [&] (char c) {
            if(c==')' or c==']' or c=='}') {
                return true;
            }
            return false;
        };
        
        auto rev = [&] (char c) {
            if(c==')') {
                return '(';
            }
            if(c=='}') {
                return '{';
            }
            if(c==']') {
                return '[';
            }
            return ' ';
        };
        
        stack<char> st;
        for(auto i:s) {
            if(st.empty()) {
                if(close(i)) {
                    return false;
                }
                st.push(i);
            }
            else if(close(i)) {
                if(st.top()==rev(i)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                st.push(i);
            }
        }
        return st.empty();
    }
};