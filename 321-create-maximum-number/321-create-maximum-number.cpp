class Solution {
public:
    vector<int> maxsubseq(vector<int> &a,int k) {
        vector<vector<int>> pos(10);
        int n=a.size();
        for(int i=0;i<n;i++) {
            pos[a[i]].push_back(i);
        }
        vector<int> ans;
        if(k==0) {
            return ans;
        }
        int idx=0;
        while(k--) {
            for(int i=9;i>=0;i--) {
                auto it=lower_bound(pos[i].begin(),pos[i].end(),idx);
                if(it!=pos[i].end() and n-1-(*it)>=k) {
                    ans.push_back(i);
                    idx=(*it)+1;
                    break;
                }
            }
        }
        return ans;
    }
    
    vector<int> merge(vector<int> &a,vector<int> &b) {
        if(a.empty()) {
            return b;
        }
        if(b.empty()) {
            return a;
        }
        int n=a.size(),m=b.size();
        int ida=0,idb=0;
        vector<int> ans;
        
        auto maxsub = [&] (int i,int j) {
            while(i<n and j<m) {
                if(a[i]>b[j]) {
                    return 1;
                }
                if(b[j]>a[i]) {
                    return 0;
                }
                i++;
                j++;
            }
            if(i==n) {
                return 0;
            }
            return 1;
        };
        
        while(ida<n and idb<m) {
            if(maxsub(ida,idb)) {
                ans.push_back(a[ida]);
                ida++;
            }
            else {
                ans.push_back(b[idb]);
                idb++;
            }
        }
        while(ida<n) {
            ans.push_back(a[ida]);
            ida++;
        }
        while(idb<m) {
            ans.push_back(b[idb]);
            idb++;
        }
        return ans;
    }
    
    vector<int> lexmax(vector<int> &a,vector<int> &b) {
        int n=a.size(),m=b.size();
        for(int i=0;i<min(n,m);i++) {
            if(a[i]>b[i]) {
                return a;
            }
            else if(b[i]>a[i]) {
                return b;
            }
        }
        if(n>m) {
            return a;
        }
        else {
            return b;
        }
    }
    
    vector<int> maxNumber(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(),m=b.size();
        vector<int> ans(k);
        for(int i=max(0,k-m);i<=min(n,k);i++) {
            vector<int> v1=maxsubseq(a,i);
            vector<int> v2=maxsubseq(b,k-i);
            vector<int> v=merge(v1,v2);
            ans=lexmax(ans,v);
        }
        return ans;
    }
};