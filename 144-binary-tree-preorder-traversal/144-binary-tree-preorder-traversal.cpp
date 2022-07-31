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
                TreeNode* thread=curr->left;
                while(thread->right and thread->right!=curr) {
                    thread=thread->right;
                }
                if(thread->right) {
                    curr=curr->right;
                    thread->right=NULL;
                }
                else {
                    thread->right=curr;
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