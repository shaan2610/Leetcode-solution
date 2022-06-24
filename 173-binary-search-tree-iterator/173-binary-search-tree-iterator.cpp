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
class BSTIterator {
public:
    vector<int> inorder;
    int idx=0;
    
    void traversal(TreeNode*root,vector<int> &inorder) {
        if(not root) {
            return;
        }
        traversal(root->left,inorder);
        inorder.push_back(root->val);
        traversal(root->right,inorder);
    }
    
    BSTIterator(TreeNode* root) {
        traversal(root,inorder);
    }
    
    int next() {
        if(hasNext()) {
            return inorder[idx++];
        }
        return -1;
    }
    
    bool hasNext() {
        if(idx<inorder.size()) {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */