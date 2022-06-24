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
    bool isBST(TreeNode* curr,long mn,long mx) {
        if(not curr) {
            return true;
        }
        if(curr->val>=mn and curr->val<=mx) {
            return (isBST(curr->left,mn,curr->val-1l) and isBST(curr->right,curr->val+1l,mx));
        }
        else {
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        long mx=INT_MAX,mn=INT_MIN;
        return isBST(root,mn,mx);
    }
};