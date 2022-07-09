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
    int helper(struct TreeNode* node,int &ans) {
        int val=node->val;
        if(node->left) {
            int leftMin=helper(node->left,ans);
            val=min(val,leftMin);
            ans=max(ans,abs(node->val-leftMin));
        }
        if(node->right) {
            int rightMin=helper(node->right,ans);
            val=min(val,rightMin);
            ans=max(ans,abs(node->val-rightMin));
        }
        return val;
    }
    
    int helper1(struct TreeNode* node,int &ans) {
        int val=node->val;
        if(node->left) {
            int leftMin=helper1(node->left,ans);
            val=max(val,leftMin);
            ans=max(ans,abs(node->val-leftMin));
        }
        if(node->right) {
            int rightMin=helper1(node->right,ans);
            cout<<rightMin<<" ";
            val=max(val,rightMin);
            ans=max(ans,abs(node->val-rightMin));
        }
        return val;
    }

    int maxAncestorDiff(TreeNode* root) {
        if(not root) {
            return -1;
        }
        int ans=0;
        TreeNode* temp=root;
        helper(root,ans);
        helper1(temp,ans);
        return ans;
    }
};