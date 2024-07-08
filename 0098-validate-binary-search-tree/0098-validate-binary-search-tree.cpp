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
    bool isBST(TreeNode* curr, long min_range, long max_range) {
        if(curr == NULL) {
            return true;
        }
        if(curr -> val >= min_range and curr -> val <= max_range) {
            // Left child --> LST
            bool is_lst_BST = isBST(curr -> left, min_range, curr -> val - 1l);
            // Right child --> RST
            bool is_rst_BST = isBST(curr -> right, curr -> val + 1l, max_range);
            if(is_lst_BST == true and is_rst_BST == true) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        // 1. All the nodes of LST should be smaller than root value.
        // 2. All the nodes of RST should be greater than root value.
        // 3. LST should also be a BST
        // 4. RST should also be a BST
        long max_range = INT_MAX, min_range = INT_MIN;
        return isBST(root, min_range, max_range);
    }
};