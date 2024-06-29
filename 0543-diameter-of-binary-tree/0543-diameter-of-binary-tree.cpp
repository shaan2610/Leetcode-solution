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
    int helper(TreeNode* node, int &diameter) { // Returns the max depth of tree rooted at node
        if(node == NULL) {
            return 0;
        }
        int lst_depth = helper(node -> left, diameter);
        int rst_depth = helper(node -> right, diameter);
        diameter = max(diameter, lst_depth + rst_depth);
        return 1 + max(lst_depth, rst_depth);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        if(root == NULL) {
            return 0;
        }
        helper(root, diameter);
        return diameter;
    }
};