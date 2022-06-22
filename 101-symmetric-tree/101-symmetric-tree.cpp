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
    bool isSymmetric(TreeNode* root) {
        if(not root) {
            return true;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int chk=0;
        while(not q.empty()) {
            int z=q.size();
            vector<pair<int,int>> v;
            while(z--) {
                auto p=q.front();
                TreeNode* node=p.first;
                int deviation=p.second;
                q.pop();
                v.push_back({node->val,deviation});
                if(node->left) {
                    q.push({node->left,deviation-1});
                }
                if(node->right) {
                    q.push({node->right,deviation+1});
                }
            }
            int sz=v.size();
            int i=0,j=sz-1;
            if(sz&1) {
                if(chk==0) {
                    chk++;
                }
                else {
                    return false;
                }
            }
            while(i<=j) {
                if(v[i].first==v[j].first and v[i].second+v[j].second==0) {
                    i++;
                    j--;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};