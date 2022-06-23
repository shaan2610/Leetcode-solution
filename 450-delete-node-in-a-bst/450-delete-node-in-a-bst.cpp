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
    TreeNode* getRightPtr(TreeNode* curr) {
        while(curr->right) {
            curr=curr->right;
        }
        return curr;
    }
    
    TreeNode* deleteRoot(TreeNode* root) {
        if(not root->right) {
            return root->left;
        }
        if(not root->left) {
            return root->right;
        }
        TreeNode* leftChild=root->left;
        TreeNode* rightChild=root->right;
        TreeNode* rightMost=getRightPtr(leftChild);
        rightMost->right=rightChild;
        return leftChild;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(not root) {
            return NULL;
        }
        if(root->val==key) {
            return deleteRoot(root);
        }
        TreeNode* curr=root;
        TreeNode* parent=NULL;
        while(curr) {
            if(key>curr->val) {
                if(curr->right and curr->right->val==key) {
                    curr->right=deleteRoot(curr->right);
                    return root;
                }
                else {
                    curr=curr->right;
                }
            }
            else {
                if(curr->left and curr->left->val==key) {
                    curr->left=deleteRoot(curr->left);
                    return root;
                }
                else {
                    curr=curr->left;
                }
            }
        }
        return root;
    }
};