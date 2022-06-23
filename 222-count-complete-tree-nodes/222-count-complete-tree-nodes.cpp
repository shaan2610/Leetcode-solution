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
    
    int height(TreeNode* node,int dir) {
        int ans=0;
        while(node) {
            ans++;
            if(dir) {
                node=node->left;
            }
            else {
                node=node->right;
            }
        }
        return ans;
    }
    
    int countNodes(TreeNode* root) {
        // Using property that if the left height ree is equal to right height of tree then cnt = (1<<h)-1
        if(not root) {
            return 0;
        }
        int leftHeight=height(root,1);
        int rightHeight=height(root,0);
        if(leftHeight==rightHeight) {
            return ((1<<leftHeight)-1);
        }
        else {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};