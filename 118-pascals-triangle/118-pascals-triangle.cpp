class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<int> temp(1,1);
        vector<vector<int>> ans;
        ans.push_back(temp);
        int m=n;
        n--;
        while(n--) {
            temp.clear();
            temp.resize(m-n);
            temp[0]=1;
            temp.back()=1;
            vector<int> v=ans.back();
            for(int i=1;i<m-n-1;i++) {
                temp[i]=v[i-1]+v[i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};