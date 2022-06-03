class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int num1=0,num2=0,freq1=0,freq2=0,n=nums.size();
        for(int i=0;i<n;i++) {
            if(nums[i]==num1) {
                freq1++;
            }
            else if(nums[i]==num2) {
                freq2++;
            }
            else if(freq1==0) {
                num1=nums[i];
                freq1++;
            }
            else if(freq2==0) {
                num2=nums[i];
                freq2++;
            }
            else {
                freq1--;
                freq2--;
            }
        }
        freq1=0;
        freq2=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==num1) {
                freq1++;
            }
            else if(nums[i]==num2) {
                freq2++;
            }
        }
        if(freq1>n/3) {
            ans.push_back(num1);
        }
        if(freq2>n/3) {
            ans.push_back(num2);
        }
        return ans;
    }
};