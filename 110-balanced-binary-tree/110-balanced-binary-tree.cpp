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
    int helper(TreeNode* curr,bool &ans) {
        if(not curr or not ans) {
            return 0;
        }
        int leftDepth=0,rightDepth=0;
        if(curr->left) {
            leftDepth=1+helper(curr->left,ans);
        }
        if(not ans) {
            return 0;
        }
        if(curr->right) {
            rightDepth=1+helper(curr->right,ans);
        }
        if(abs(leftDepth-rightDepth)>1) {
            ans=false;
        }
        return max(leftDepth,rightDepth);
    }
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        helper(root,ans);
        return ans;
    }
};