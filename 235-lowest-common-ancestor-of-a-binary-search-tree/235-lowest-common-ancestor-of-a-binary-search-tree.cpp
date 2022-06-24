/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(not root) {
            return NULL;
        }
        if(root==p or root==q) {
            return root;
        }
        int mn=min(p->val,q->val),mx=max(p->val,q->val);
        if(mn<root->val and mx>root->val) {
            return root;
        }
        if(mx<root->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        if(mn>root->val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};