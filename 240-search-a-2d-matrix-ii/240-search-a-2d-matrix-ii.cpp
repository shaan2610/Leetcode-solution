class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        auto binarySearch = [&] (int row) {
            int low=0,high=m-1;
            while(low<=high) {
                int mid=(low+high);
                if(matrix[row][mid]==target) {
                    return true;
                }
                else if(matrix[row][mid]<target) {
                    low=mid+1;
                }
                else {
                    high=mid-1;
                }
            }
            return false;
        };
        for(int i=0;i<n;i++) {
            if(binarySearch(i)) {
                return true;
            }
        }
        return false;
    }
};