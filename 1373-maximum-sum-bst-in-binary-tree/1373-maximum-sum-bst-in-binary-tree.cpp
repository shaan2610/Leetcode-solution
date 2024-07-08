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
    long inf = 1e10;
    long get_max_sum(TreeNode* curr, long &min_val, long &max_val, long &ans) {
        if(curr == NULL) {      // If tree is empty then sum is 0
            return 0l;
        }
        
        // Check if the subtree rooted at curr is a BST or not
        
        // LST
        long lst_min = inf, lst_max = -inf;     // Min and max value of LST
        long lst_sum = get_max_sum(curr -> left, lst_min, lst_max, ans);
        // RST
        long rst_min = inf, rst_max = -inf;
        long rst_sum = get_max_sum(curr -> right, rst_min, rst_max, ans);
        
        long curr_val = curr -> val;
        min_val = min({min_val, curr_val, lst_min, rst_min});
        max_val = max({max_val, curr_val, lst_max, rst_max});
        if(lst_sum != -inf and rst_sum != -inf and curr_val > lst_max and curr_val < rst_min) {
            // Current subtree is a BST
            long curr_sum = lst_sum + rst_sum + curr_val;
            ans = max(ans, curr_sum);
            return curr_sum;
        }
        else {
            // The current subtree is not a BST
            return -inf;        // Whenever fxn returns -inf, it implies it is not a BST
        }
    }
    
    int maxSumBST(TreeNode* root) {
        long max_val = inf, min_val = -inf, ans = 0;
        get_max_sum(root, min_val, max_val, ans);
        return int(ans);
    }
};