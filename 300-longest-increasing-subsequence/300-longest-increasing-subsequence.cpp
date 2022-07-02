class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        if(a.empty()) {
            return 0;
        }
        int n=a.size();
        vector<int> tail;
        tail.push_back(a[0]);
        for(int i=1;i<n;i++) {
            auto it=lower_bound(tail.begin(),tail.end(),a[i]);
            if(it==tail.end()) {
                tail.push_back(a[i]);
            }
            else {
                int idx=it-tail.begin();
                tail[idx]=a[i];
            }
        }
        return tail.size();
    }
};