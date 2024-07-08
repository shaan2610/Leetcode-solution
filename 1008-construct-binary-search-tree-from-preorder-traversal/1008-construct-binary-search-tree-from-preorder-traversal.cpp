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
    TreeNode* helper(vector<int>& preorder, int &idx, int upper_bound) {
        int n = preorder.size();
        if(idx >= n) {
            return NULL;
        }
        if(preorder[idx] >= upper_bound) {
            return NULL;
        }
        int root_value = preorder[idx];
        TreeNode* root = new TreeNode(root_value);
        idx++;
        root -> left = helper(preorder, idx, root_value);
        root -> right = helper(preorder, idx, upper_bound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int upper_bound = 2000, idx = 0;
        return helper(preorder, idx, upper_bound);
    }
};