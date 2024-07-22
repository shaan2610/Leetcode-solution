class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n);
        ans[0] = 1;
        int ptr2 = 0, ptr3 = 0, ptr5 = 0;
        for(int i=1;i<n;i++) {
            ans[i] = min({2 * ans[ptr2], 3 * ans[ptr3], 5 * ans[ptr5]});
            if(ans[i] == 2 * ans[ptr2]) {
                ptr2++;
            }
            if(ans[i] == 3 * ans[ptr3]) {
                ptr3++;
            }
            if(ans[i] == 5 * ans[ptr5]) {
                ptr5++;
            }
        }
        return ans.back();
    }
};