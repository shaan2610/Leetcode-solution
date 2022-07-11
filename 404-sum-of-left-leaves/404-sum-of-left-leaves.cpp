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
    void sumOfLeaf(TreeNode* node,bool flag,int &sum) {
        if(not node) {
            return;
        }
        if(not node->left and not node->right) {
            if(flag) {
                sum+=node->val;
            }
            return;
        }
        bool leftFlag=true,rightFlag=false;
        sumOfLeaf(node->left,leftFlag,sum);
        sumOfLeaf(node->right,rightFlag,sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(not root) {
            return 0;
        }
        if(not root->left and not root->right) {
            return 0;
        }
        int sum=0;
        bool flag=true;
        sumOfLeaf(root,flag,sum);
        return sum;
    }
};