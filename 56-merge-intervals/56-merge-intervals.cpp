class Solution {
public:
    
    static bool srt(const vector<int> &a,const vector<int> &b) {
        if(a[0]<b[0]) {
            return true;
        }
        if(b[0]<a[0]) {
            return false;
        }
        if(a[1]<b[1]) {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),srt);
        vector<vector<int>> ans;
        int st=intervals[0][0],en=intervals[0][1];
        int n=intervals.size();
        for(int i=0;i<n;i++) {
            int l=intervals[i][0],r=intervals[i][1];
            if(l>=st and l<=en) {
                en=max(en,r);
            }
            else {
                vector<int> range;
                range.push_back(st);
                range.push_back(en);
                ans.push_back(range);
                st=l;
                en=r;
            }
        }
        vector<int> range;
        range.push_back(st);
        range.push_back(en);
        ans.push_back(range);
        return ans;
    }
};