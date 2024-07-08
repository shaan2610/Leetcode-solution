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
    int kthSmallest(TreeNode* root, int &k) {
        if(root == NULL) {
            return -1;          // This will indicate that there is no tree or NULL pointer
        }
        // Traverse the LST
        int left = kthSmallest(root -> left, k);
        if(left != -1) {        // We already found the answer
            return left;
        }
        k--;
        if(k == 0) {
            return root -> val;
        }
        int right = kthSmallest(root -> right, k);
        if(right != -1) {
            return right;
        }
        return -1;      // Kth smallest element not found
    }
};