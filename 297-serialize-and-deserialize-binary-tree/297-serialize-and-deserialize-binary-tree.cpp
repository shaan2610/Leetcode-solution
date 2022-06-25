/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    void helper(TreeNode* curr,string &code) {
        queue<TreeNode*> q;
        q.push(curr);
        while(not q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if(node) {
                code+=to_string(node->val);
                code.push_back(',');
                q.push(node->left);
                q.push(node->right);
            }
            else {
                code+=to_string(-1e4);
                code.push_back(',');
            }
        }
    }
    
    string serialize(TreeNode* root) {
        string code;
        helper(root,code);
        return code;
    }

    // Decodes your encoded data to tree.
    
    TreeNode* deserialize(string data) {
        vector<int> traversal;
        string s1;
        for(auto i:data) {
            if(i==',') {
                traversal.push_back(stoi(s1));
                s1.clear();
            }
            else {
                s1.push_back(i);
            }
        }
        if(traversal[0]==-1e4) {
            return NULL;
        }
        queue<pair<TreeNode*,int>> q;
        TreeNode* ans=new TreeNode(0);
        q.push({ans,1});
        TreeNode* root=ans;
        int idx=0;
        while(not q.empty()) {
            auto p=q.front();
            TreeNode* node=p.first;
            int dir=p.second;
            q.pop();
            if(dir==1) {
                if(traversal[idx]!=-1e4) {
                    node->right=new TreeNode(traversal[idx]);
                    q.push({node->right,-1});
                    q.push({node->right,1});
                }
            }
            else {
                if(traversal[idx]!=-1e4) {
                    node->left=new TreeNode(traversal[idx]);
                    q.push({node->left,-1});
                    q.push({node->left,1});
                }
            }
            idx++;
        }
        return root->right;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));