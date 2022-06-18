class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size(),m=version2.size();
        int i=0,j=0;
        while(i<n and j<m) {
            int i1=i;
            while(i1<n and version1[i1]!='.') {
                i1++;
            }
            int num1=stoi(version1.substr(i,i1-i));
            i=i1+1;
            int j1=j;
            while(j1<m and version2[j1]!='.') {
                j1++;
            }
            int num2=stoi(version2.substr(j,j1-j));
            j=j1+1;
            if(num1<num2) {
                return -1;
            }
            if(num1>num2) {
                return 1;
            }
        }
        while(i<n) {
            int i1=i;
            while(i1<n and version1[i1]!='.') {
                i1++;
            }
            int num1=stoi(version1.substr(i,i1-i));
            i=i1+1;
            if(num1) {
                return 1;
            }
        }
        while(j<m) {
            int j1=j;
            while(j1<m and version2[j1]!='.') {
                j1++;
            }
            int num2=stoi(version2.substr(j,j1-j));
            j=j1+1;
            if(num2) {
                return -1;
            }
        }
        return 0;
    }
};