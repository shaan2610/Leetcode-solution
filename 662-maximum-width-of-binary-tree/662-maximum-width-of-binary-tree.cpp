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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(not q.empty()) {
            int z=q.size();
            long long mn=1e18,mx=-1e18;
            int mn1=q.front().second;
            while(z--) {
                auto p=q.front();
                q.pop();
                TreeNode* node=p.first;
                long long dev=p.second;
                dev-=mn1;
                mn=min(mn,dev);
                mx=max(mx,dev);
                if(node->left) {
                    q.push({node->left,2ll*dev+1ll});
                }
                if(node->right) {
                    q.push({node->right,2ll*dev+2ll});
                }
            }
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};