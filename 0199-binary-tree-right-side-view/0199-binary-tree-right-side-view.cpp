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
    vector<int> rightSideView(TreeNode* root) {
//         In every level the rightmost node will be seen
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(not q.empty()) {
            int curr_sz = q.size();
            for(int i=0;i<curr_sz;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(i == curr_sz - 1) {
                    ans.push_back(curr -> val);
                }
                if(curr -> left) {
                    q.push(curr -> left);
                }
                if(curr -> right) {
                    q.push(curr -> right);
                }
            }
        }
        return ans;
    }
};