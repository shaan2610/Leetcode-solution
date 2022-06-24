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
    TreeNode* helper(vector<int>& preorder,int st,int en) {
        if(st>en) {
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[st]);
        int idx=st;
        while(idx<=en and preorder[idx]<=preorder[st]) {
            idx++;
        }
        node->left=helper(preorder,st+1,idx-1);
        node->right=helper(preorder,idx,en);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        return helper(preorder,0,n-1);
    }
};