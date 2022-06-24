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
    
    TreeNode* getBST(vector<int> &inorder,int st,int en) {
        if(st>en) {
            return NULL;
        }
        int mid=(st+en)/2;
        TreeNode* node=new TreeNode(inorder[mid]);
        node->left=getBST(inorder,st,mid-1);
        node->right=getBST(inorder,mid+1,en);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) {
            return NULL;
        }
        return getBST(nums,0,n-1);
    }
};