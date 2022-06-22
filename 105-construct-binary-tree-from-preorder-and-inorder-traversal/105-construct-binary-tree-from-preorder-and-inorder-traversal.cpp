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
    
    TreeNode* helper(vector<int> &preorder,int sp,int ep,vector<int> &inorder,int si,int ei) {
        if(sp>ep or si>ei) {
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[sp]);
        int inLeft=si;
        while(inorder[inLeft]!=preorder[sp]) {
            inLeft++;
        }
        int sz=inLeft-si;
        node->left=helper(preorder,sp+1,sp+1+sz-1,inorder,si,inLeft-1);
        node->right=helper(preorder,sp+1+sz,ep,inorder,inLeft+1,ei);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
};