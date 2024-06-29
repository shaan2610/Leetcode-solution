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
    int helper(TreeNode* node, bool &is_balanced) { // Returns the max depth of tree rooted at node
        if(node == NULL) {
            return 0;
        }
        int lst_depth = helper(node -> left, is_balanced);
        int rst_depth = helper(node -> right, is_balanced);
        if(abs(lst_depth - rst_depth) > 1) {
            is_balanced = false;
        }
        return 1 + max(lst_depth, rst_depth);
    }
    
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        if(root == NULL) {
            return true;
        }
        helper(root, is_balanced);
        return is_balanced;
    }
};