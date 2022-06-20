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
    
    int helper(TreeNode* curr,int &ans) {
        if(not curr) {
            return 0;
        }
        int maxLeft=helper(curr->left,ans);
        int maxRight=helper(curr->right,ans);
        int currVal=0;
        if(curr->left) {
            maxLeft++;
        }
        if(curr->right) {
            maxRight++;
        }
        ans=max(ans,maxLeft+maxRight);
        return max(maxLeft,maxRight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(not root) {
            return 0;
        }
        int ans=0;
        helper(root,ans);
        return ans;
    }
};