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
    int helper(TreeNode* node, int &ans) {  // Returns the max path sum of all path from node to all the childs in the subtree rooted at node
        if(node == NULL) {
            return 0;
        }
        int lst_sum = max(helper(node -> left, ans), 0);
        int rst_sum = max(helper(node -> right, ans), 0);
        int curr_sum = lst_sum + rst_sum + node -> val;
        ans = max(ans, curr_sum);
        return node -> val + max(lst_sum, rst_sum);
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};