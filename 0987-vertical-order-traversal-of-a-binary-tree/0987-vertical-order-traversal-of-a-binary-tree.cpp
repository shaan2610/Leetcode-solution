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

class NodeDesc {
public:
    TreeNode* node;
    int row, col;
    NodeDesc(TreeNode* curr, int r, int c) {
        node = curr;
        row = r;
        col = c;
    }
};

class Solution {
public:
    static bool cmp(pair<TreeNode*, int> &a, pair<TreeNode*, int> &b) {
        TreeNode* node_a = a.first;
        TreeNode* node_b = b.first;
        int row_a = a.second, row_b = b.second;
        if(row_a < row_b) {
            return true;
        }
        if(row_a > row_b) {
            return false;
        }
        
//         if row_a == row_b
        if(node_a -> val < node_b -> val) {
            return true;
        }
        else {
            return false;
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        
//         Level order Traversal
//         {node, {row, col}}
        queue<NodeDesc*> q;
        NodeDesc* root_node = new NodeDesc(root, 0, 0);
        q.push(root_node);
        
        map<int, vector<pair<TreeNode*, int>>> mp;
        
        while(not q.empty()) {
            int curr_sz = q.size();
            for(int i=0;i<curr_sz;i++) {
                NodeDesc* curr = q.front();
                q.pop();
                TreeNode* curr_node = curr -> node;
                int row = curr -> row, col = curr -> col;
                mp[col].push_back({curr_node, row});
                if(curr_node -> left) {     // Left child
                    NodeDesc* left_child = new NodeDesc(curr_node -> left, row + 1, col - 1);
                    q.push(left_child);
                }
                if(curr_node -> right) {    // Right child
                    NodeDesc* right_child = new NodeDesc(curr_node -> right, row + 1, col + 1);
                    q.push(right_child);
                }
            }
        }
        
        // i --> int, vector<pair<TreeNode*, int>>
        // j --> pair<TreeNode*, int>
        
        for(auto i:mp) {
            int col = i.first;
            vector<pair<TreeNode*, int>> nodes_in_col = i.second;
            sort(nodes_in_col.begin(), nodes_in_col.end(), cmp);
            vector<int> temp;
            for(auto j:nodes_in_col) {
                TreeNode* curr = j.first;
                temp.push_back(curr -> val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};