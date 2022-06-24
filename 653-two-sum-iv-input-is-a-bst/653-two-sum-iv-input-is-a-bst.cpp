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
    
    stack<TreeNode*> inc,dec;
    
    void leftMost(TreeNode* node) {
        while(node) {
            inc.push(node);
            node=node->left;
        }
    }
    
    void rightMost(TreeNode* node) {
        while(node) {
            dec.push(node);
            node=node->right;
        }
    }
    
    bool findTarget(TreeNode* root, int k) {
        leftMost(root);
        rightMost(root);
        while(not inc.empty() and not dec.empty()) {
            TreeNode* node1=inc.top();
            TreeNode* node2=dec.top();
            if(node1->val>=node2->val) {
                break;
            }
            int currSum=node1->val+node2->val;
            if(currSum==k) {
                return true;
            }
            else if(currSum<k) {
                inc.pop();
                if(node1->right) {
                    leftMost(node1->right);
                }
            }
            else {          
                dec.pop();
                if(node2->left) {
                    rightMost(node2->left);
                }
            }
        }
        return false;
    }
};