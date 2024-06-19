class Solution {
public:
    bool is_opening(char c) {   // True if it is a opening bracket else false
        if(c == '(' or c == '{' or c == '[') {
            return true;
        }
        else {
            return false;
        }
    }
    
    char opening_pair(char c) {
        if(c == ')') {
            return '(';
        }
        if(c == '}') {
            return '{';
        }
        return '[';
    }
    
    bool isValid(string s) {
        int n = s.size();
        
        stack<char> st;
        
        for(int i=0;i<n;i++) {
            if(st.empty()) {
                if(is_opening(s[i])) {
                    st.push(s[i]);
                }
                else {  // Closing bracket
//                     There is no opening pair for the closing bracket
                    return false;
                }
            }
            else {
                if(is_opening(s[i])) {
                    st.push(s[i]);
                }
                else {  // Closing bracket
                    if(st.top() == opening_pair(s[i])) {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        if(st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};