class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        
        auto chkDigit = [&] (char c) {
            if(c>='0' and c<='9') {
                return true;
            }
            return false;
        };
        
        long long chk=1,ans=0,st=0;
        for(st=0;st<n;st++) {
            if(s[st]==' ') {
                continue;
            }
            break;
        }
        if(st<n and s[st]=='-') {
            chk=-1;
            st++;
        }
        else if(st<n and s[st]=='+') {
           st++;
        }
        for(int i=st;i<n;i++) {
            if(not chkDigit(s[i])) {
                break;
            }
            long long res=ans;
            res*=10;
            res+=(s[i]-'0');
            if(chk==1 and res>INT_MAX) {
                return INT_MAX;
            }
            if(chk==-1 and -res<INT_MIN) {
                return INT_MIN;
            }
            ans=res;
            // cout<<ans;
        }
        
        ans*=chk;
        return ans;
    }
};