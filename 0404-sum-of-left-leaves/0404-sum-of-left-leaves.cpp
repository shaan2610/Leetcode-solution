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
    
//     dir = 1 --> left child
//     dir = 2 --> right child
//     dir = 0 --> root
    
    void helper(TreeNode* node, int &ans, int dir) {
        if(node == NULL) {
            return;
        }
        if(node -> left == NULL and node -> right == NULL and dir == 1) {   // Left leaf
            ans += node -> val;
        }
        helper(node -> left, ans, 1);
        helper(node -> right, ans, 2);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root, ans, 0);
        return ans;
    }
};