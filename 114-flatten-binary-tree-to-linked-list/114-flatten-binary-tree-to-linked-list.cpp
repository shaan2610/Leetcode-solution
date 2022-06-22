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
    void helper(TreeNode* curr,vector <TreeNode*> &ans) {
        if(not curr) {
            return;
        }
        ans.push_back(curr);
        helper(curr->left,ans);
        helper(curr->right,ans);
    }
    
    void flatten(TreeNode* &root) {
        vector<TreeNode*> ans;
        helper(root,ans);
        TreeNode *node=new TreeNode(0);
        for(auto i:ans) {
            node->right=i;
            node->left=NULL;
            node=node->right;
        }
        node->left=NULL;
    }
};