class Solution {
public:
    int findDuplicate(vector<int>& a) {
         int n=a.size();
        int slow=a[0],fast=a[0];
        do {
            slow=a[slow];
            fast=a[a[fast]];
        } while(slow!=fast);
        fast = a[0];
        while(fast!=slow) {
            fast=a[fast];
            slow=a[slow];
        }
        return fast;
    }
};