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
    bool helper(TreeNode* curr1,TreeNode* curr2) {
        if(not curr1 or not curr2) {
            return (curr1==curr2);
        }
        return (helper(curr1->left,curr2->right) and helper(curr1->right,curr2->left) and curr1->val==curr2->val);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(not root) {
            return true;
        }
        return helper(root->left,root->right);
    }
};