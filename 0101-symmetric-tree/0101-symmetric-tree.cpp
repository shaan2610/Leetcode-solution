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
    bool helper(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL or node2 == NULL) {
            if(node1 == node2) {
                return true;
            }
            else {
                return false;
            }
        }
        if(node1 -> val == node2 -> val and helper(node1 -> left, node2 -> right) and helper(node1 -> right, node2 -> left)) {
            return true;
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {  // Empty tree is also a symmetric tree
            return true;
        }
        return helper(root -> left, root -> right);
    }
};