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
    TreeNode *ptr1=NULL,*ptr2=NULL,*par1=NULL,*par2=NULL;
    void changeBST(TreeNode* curr,TreeNode* &prev) {
        if(not curr) {
            return;
        }
        changeBST(curr->left,prev);
        if(prev->val>curr->val) {
            if(ptr1) {
                ptr2=curr;
                par2=prev;
            }
            else {
                ptr1=curr;
                par1=prev;
            }
        }
        prev=curr;
        changeBST(curr->right,prev);
    }
    
    void recoverTree(TreeNode* root) {
        if(not root) {
            return;
        }
        TreeNode *prev=new TreeNode(INT_MIN);
        changeBST(root,prev);
        if(ptr2) {
            int val=par1->val;
            par1->val=ptr2->val;
            ptr2->val=val;
        }
        else {
            int val=par1->val;
            par1->val=ptr1->val;
            ptr1->val=val;
        }
    }
};