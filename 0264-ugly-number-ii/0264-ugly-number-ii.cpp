class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);
        long long ans;
        while(n--) {
            ans = *st.begin();
            st.erase(st.begin());
            st.insert(ans * 2ll);
            st.insert(ans * 3ll);
            st.insert(ans * 5ll);
        }
        return ans;
    }
};