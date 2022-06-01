class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int> temp(1,1);
        int m=n;
        n--;
        while(n--) {
            vector<int> v(m-n,1);
            for(int i=1;i<m-n-1;i++) {
                v[i]=temp[i]+temp[i-1];
            }
            swap(v,temp);
        }
        return temp;
    }
};