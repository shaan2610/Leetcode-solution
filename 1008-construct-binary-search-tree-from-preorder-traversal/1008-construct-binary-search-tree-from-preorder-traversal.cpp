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
    TreeNode* helper(vector<int>& preorder,int &i,int upperBound) {
        int n=preorder.size();
        if(i>=n or preorder[i]>=upperBound) {
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[i++]);
        node->left=helper(preorder,i,node->val);
        node->right=helper(preorder,i,upperBound);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        int i=0;
        return helper(preorder,i,INT_MAX);
    }
};