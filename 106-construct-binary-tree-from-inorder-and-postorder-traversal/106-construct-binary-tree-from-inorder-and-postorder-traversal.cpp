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
    
    TreeNode* helper(vector<int> &inorder,int si,int ei,vector<int> &postorder,int sp,int ep) {
        if(si>ei or sp>ep) {
            return NULL;
        }
        int inLeft=si;
        while(inorder[inLeft]!=postorder[ep]) {
            inLeft++;
        }
        int sz=inLeft-si;
        TreeNode* node=new TreeNode(postorder[ep]);
        node->left=helper(inorder,si,si+sz-1,postorder,sp,sp+sz-1);
        node->right=helper(inorder,inLeft+1,ei,postorder,sp+sz,ep-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return helper(inorder,0,n-1,postorder,0,n-1);
    }
};