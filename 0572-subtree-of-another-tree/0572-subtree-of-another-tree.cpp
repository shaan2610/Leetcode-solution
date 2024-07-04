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
    bool is_similar(TreeNode* node1, TreeNode* node2) {  // Check if both trees rooted at node1 and node2 are similar or not
        if(node1 == NULL and node2 == NULL) {       // Both trees are null
            return true;
        }
        if(node1 == NULL or node2 == NULL) {        // One of them are null
            return false;
        }
        if(node1 -> val == node2 -> val and is_similar(node1 -> left, node2 -> left) and is_similar(node1 -> right, node2 -> right)) {
            return true;
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) {
            return false;
        }
        if(is_similar(root, subRoot)) {
            return true;
        }
        if(isSubtree(root -> left, subRoot)) {
            return true;
        }
        if(isSubtree(root -> right, subRoot)) {
            return true;
        }
        return false;
    }
};