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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(not root) {
            return NULL;
        }
        if(root->val==key) {
            if(not root->left) {
                return root->right;
            }
            else if(not root->right) {
                return root->left;
            }
            else {
                TreeNode* left=root->left;
                TreeNode* newRoot=root->left;
                TreeNode* right=root->right;
                while(left->right) {
                    left=left->right;
                }
                left->right=right;
                return newRoot;
            }
        }
        TreeNode* curr=root;
        TreeNode* newRoot=NULL;
        while(curr) {
            if(curr->val==key) {
                TreeNode* left=curr->left;
                TreeNode* right=curr->right;
                if(left) {
                    if(newRoot->left==curr) {
                        newRoot->left=left;
                    }
                    else {
                        newRoot->right=left;
                    }
                    while(left->right) {
                        left=left->right;
                    }
                    left->right=right;
                    return root;
                }
                else if(right) {
                    if(newRoot->left==curr) {
                        newRoot->left=right;
                    }
                    else {
                        newRoot->right=right;
                    }
                    while(right->left) {
                        right=right->left;
                    }
                    right->left=left;
                    return root;
                }
                else {
                    if(newRoot->left and newRoot->left->val==key) {
                        newRoot->left=NULL;
                    }
                    else {
                        newRoot->right=NULL;
                    }
                    return root;
                }
            }
            else if(key>curr->val) {
                newRoot=curr;
                curr=curr->right;
            }
            else {
                newRoot=curr;
                curr=curr->left;
            }
        }
        return root;
    }
};