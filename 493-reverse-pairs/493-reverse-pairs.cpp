class Solution {
public:
    
    
    
    int merge(vector<int> &arr,int l,int mid,int r) {
        vector<int> temp(r-l+1);
        int idx1=l,idx2=mid,idx=0,ans=0;
        int i=l,j=mid;
        
        auto top = [&] (int x,int y) {
            int res=x/y;
            if(x%y) {
                res++;
            }
            return res;
        };
        
        for(int i=l;i<mid;i++) {
            while(j<=r and arr[i]>2ll*arr[j]) {
                j++;
            }
            ans+=(j-mid);
        }
        while(idx1<mid and idx2<=r) {
            if(arr[idx1]<=arr[idx2]) {
                temp[idx]=arr[idx1];
                idx++;
                idx1++;
            }
            else {
                temp[idx]=arr[idx2];
                idx++;
                idx2++;
            }
        }
        while(idx1<mid) {
            temp[idx]=arr[idx1];
            idx++;
            idx1++;
        }
        while(idx2<=r) {
            temp[idx]=arr[idx2];
            idx++;
            idx2++;
        }
        for(int i=l;i<=r;i++) {
            arr[i]=temp[i-l];
        }
        return ans;
    }
    
    int countMergeSort(vector<int> &arr,int l,int r) {
        if(l>=r) {
            return 0;
        }
        int mid=(l+r)/2;
        int ans=0;
        ans+=countMergeSort(arr,l,mid);
        ans+=countMergeSort(arr,mid+1,r);
        ans+=merge(arr,l,mid+1,r);
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return countMergeSort(nums,0,n-1);
    }
};