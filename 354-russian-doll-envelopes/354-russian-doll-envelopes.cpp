class Solution {
public:
    
    static bool cmp(vector<int> &env1,vector<int> &env2) {
        if(env1[0]<env2[0]) {
            return true;
        }
        if(env1[0]>env2[0]) {
            return false;
        }
        return (env1[1]>env2[1]);
    }
    
    int LIS(vector<int> dolls) {
        int n=dolls.size();
        vector<int> tail;
        tail.push_back(dolls[0]);
        for(int i=1;i<n;i++) {
            auto it=lower_bound(tail.begin(),tail.end(),dolls[i]);
            if(it==tail.end()) {
                tail.push_back(dolls[i]);
            }
            else {
                tail[it-tail.begin()]=dolls[i];
            }
        }
        return tail.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) {
            return 0;
        }
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dolls;
        for(int i=0;i<n;i++) {
            dolls.push_back(envelopes[i][1]);
        }
        return LIS(dolls);
    }
};