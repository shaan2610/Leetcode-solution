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
        if(root == NULL) {
            return NULL;
        }
        if(root == p or root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        if(left and right) {        // One node in LST and one node in RST
            return root;
        }
        if(left == NULL) {      // Both node in RST
            return right;
        }
        if(right == NULL) {     // Both node in LST
            return left;
        }
        return NULL;
    }
};