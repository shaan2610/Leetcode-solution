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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> traversal;
        if(not root) {
            return traversal;
        }
        vector<multiset<pair<int,int>>> ans(2000);
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,1000}});
        while(not q.empty()) {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int r=p.second.first,c=p.second.second;
            ans[c].insert({r,node->val});
            if(node->left) {
                q.push({node->left,{r+1,c-1}});
            }
            if(node->right) {
                q.push({node->right,{r+1,c+1}});
            }
        }
        for(auto m:ans) {
            if(m.empty()) {
                continue;
            }
            else {
                vector<int> v;
                for(auto j:m) {
                    v.push_back(j.second);
                }
                traversal.push_back(v);
            }
        }
        return traversal;
    }
};