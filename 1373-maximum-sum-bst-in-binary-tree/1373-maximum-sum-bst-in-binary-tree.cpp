/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int getMaxSum(TreeNode* curr,int &mn,int &mx,int &ans) {
        if(not curr) {
            return 0;
        }
        int leftMin=1e9,leftMax=-1e9;
        int left=getMaxSum(curr->left,leftMin,leftMax,ans);
        int rightMin=1e9,rightMax=-1e9;
        int right=getMaxSum(curr->right,rightMin,rightMax,ans);
        int sum=left+right+curr->val;
        mn=min({mn,curr->val,leftMin,rightMin});
        mx=max({mx,curr->val,leftMax,rightMax});
        if(left!=-1e9 and right!=-1e9 and leftMax<curr->val and rightMin>curr->val) {
            ans=max(ans,sum);
            return sum;
        }
        return -1e9; 
    }
    
    int maxSumBST(TreeNode* root) {
        int mx=1e9,mn=-1e9,ans=0;
        getMaxSum(root,mn,mx,ans);
        return ans;
    }
};