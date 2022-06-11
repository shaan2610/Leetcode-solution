class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int req=(n+m+1)/2;
        
        auto rank = [&] (int num) {
            int ans=0;
            ans+=(upper_bound(nums1.begin(),nums1.end(),num-1)-nums1.begin());
            ans+=(upper_bound(nums2.begin(),nums2.end(),num-1)-nums2.begin());
            return ans;
        };
        
        auto getNumByRank = [&] (int req) {
            int low=-1e6,high=1e6;
            while(low<=high) {
                int mid=(low+high)/2;
                if(rank(mid)<req) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            double ans=low-1.0;
            return ans;
        };
        if((n+m)&1) {
            int req=(n+m+1)/2;
            return getNumByRank(req);
        }
        else {
            int req=(n+m)/2;
            double ans=(getNumByRank(req)+getNumByRank(req+1))/2.0;
            return ans;
        }
    }
};