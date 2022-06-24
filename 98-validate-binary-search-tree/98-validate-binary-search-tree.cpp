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
    
    const long inf=1e10;
    
    bool isBST(TreeNode* curr,long &mn,long &mx) {
        if(not curr) {
            return true;
        }
        long lmn=inf,lmx=-inf,val=curr->val;
        bool left=isBST(curr->left,lmn,lmx);
        if(lmx>=curr->val or not left) {
            return false;
        }
        long rmn=inf,rmx=-inf;
        bool right=isBST(curr->right,rmn,rmx);
        if(rmn<=curr->val or not right) {
            return false;
        }
        mn=min({mn,val,lmn,rmn});
        mx=max({mx,val,lmx,rmx});
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        long mn=inf,mx=-inf;
        return isBST(root,mn,mx);
    }
};