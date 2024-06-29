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
    void helper(TreeNode* node, string temp, vector<string> &ans) {
        if(node == NULL) {
            return;
        }
        if(node -> left == NULL and node -> right == NULL) {    // Leaf node
            // ==> path ends here, so there should be no -> at the end
            ans.push_back(temp +  to_string(node -> val));
        }
        helper(node -> left, temp + to_string(node -> val) + "->", ans);
        helper(node -> right, temp + to_string(node -> val) + "->", ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {        
        vector<string> ans;
        string temp;
        
        if(root == NULL) {
            return ans;
        }
        
        helper(root, temp, ans);
        return ans;
    }
};