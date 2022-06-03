class Solution {
public:
    struct segtree {
        vector<long long> t;
        long long sz;
        segtree(long long n) {
            t.resize(4*n+5);
            sz=n;
        }
        void update(long long st,long long en,long long v,long long idx,long long val) {
            if(st>en or idx<st or idx>en) {
                return;
            } 
            if(st==en) {
                t[v]=val;
                return;
            }
            long long mid=(st+en)/2;
            update(st,mid,2*v,idx,val);
            update(mid+1,en,2*v+1,idx,val);
            t[v]=t[2*v]+t[2*v+1];
        }
        void update(long long idx,long long val) {
            update(0,sz-1,1,idx,val);
        }
        long long getSum(long long st,long long en,long long v,long long l,long long r) {
            if(st>en or l>r or l>en or r<st) {
                return 0;
            }
            if(l<=st and r>=en) {
                return t[v];
            }
            long long mid=(st+en)/2;
            return (getSum(st,mid,2*v,l,r)+getSum(mid+1,en,2*v+1,l,r));
        }
        long long getSum(long long l,long long r) {
            return getSum(0,sz-1,1,l,r);
        }
    };
    
    int reversePairs(vector<int>& nums) {
        long long n=nums.size();
        vector<pair<long long,long long>> arr;
        for(long long i=0;i<n;i++) {
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        long long num=1;
        vector<long long> mp(n);
        for(long long i=0;i<n;i++) {
            long long j=i;
            while(j<n and arr[j].first==arr[i].first) {
                mp[arr[j].second]=num;
                j++;
            }
            j--;
            i=j;
            num++;
        }
        segtree st(num);
        long long ans=0;
        for(long long i=0;i<n;i++) {
            long z=nums[i],mx=arr[n-1].first,mn=arr[0].first;
            z*=2ll;
            pair<long long, long long> p1 = {2ll*nums[i]+1ll,0ll};
            auto it=lower_bound(arr.begin(),arr.end(),p1);
            if(it!=arr.end()) {
                auto p=*it;
                long long idx=p.second;
                ans+=st.getSum(mp[idx],num-1);
            }
            st.update(mp[i],st.getSum(mp[i],mp[i])+1);
        }
        return ans;
    }
};