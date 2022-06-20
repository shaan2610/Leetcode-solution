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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr) {
            if(curr->left) {
                TreeNode* prev=curr->left;
                while(prev->right and prev->right!=curr) {
                    prev=prev->right;
                }
                if(prev->right) {
                    prev->right=NULL;
                    curr=curr->right;
                }
                else {
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
            }
            else {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        return ans;
    }
};