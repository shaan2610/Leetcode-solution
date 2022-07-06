// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    void helper(int idx,string &s,string &temp,vector<string> &ans) {
        int n=s.size();
        if(not temp.empty()) {
            ans.push_back(temp);
        }
        if(idx==n) {
            return;
        }
        for(int i=idx;i<n;i++) {
            temp.push_back(s[i]);
            helper(i+1,s,temp,ans);
            temp.pop_back();
        }
    }

	vector<string> AllPossibleStrings(string s){
	    // Code here
	    vector<string> ans;
	    string temp;
	    helper(0,s,temp,ans);
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends