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
    bool is_leaf(TreeNode* node) {
        if(node -> left == NULL and node -> right == NULL) {
            return true;
        }
        return false;
    }
    
    // Returns the address of node(with value key) and it's parent
    pair<TreeNode*, TreeNode*> get_node_and_par(TreeNode* root, int key) {
        TreeNode *curr = root, *par = NULL;
        while(curr != NULL) {
            if(curr -> val == key) {
                return {curr, par};
            }
            else if(key < curr -> val) {        // Search in LST
                par = curr;
                curr = curr -> left;
            }
            else {  // key > curr -> val        Search in RST
                par = curr;
                curr = curr -> right;
            }
        }
        return {NULL, NULL};
    }
    
    TreeNode* delete_leaf(TreeNode* node, TreeNode* par) {
        // If the node which is to be deleted is the left child
        if(par -> left == node) {
            par -> left = NULL;
        }
        else {      // If the node which is to be deleted is the right child
            par -> right = NULL;
        }
        return node;
    }
    
    TreeNode* delete_single_child(TreeNode* node, TreeNode* par) {
        if(node -> left) {      // Node has a LST
            if(par -> right == node) {  // Node is the right child of parent
                par -> right = node -> left;
            }
            else {      // Node is the left child of parent
                par -> left = node -> left;
            }
        }
        else {          // Node has a RST
            if(par -> right == node) {  // Node is the right child of parent
                par -> right = node -> right;
            }
            else {      // Node is the left child of parent
                par -> left = node -> right;
            }
        }
        return node;
    }
    
    TreeNode* delete_double_child(TreeNode* node, TreeNode* par) {
        TreeNode* parent = node;
        
        // Find node having max value in LST
        TreeNode* lst_max = node -> left;
        while(lst_max -> right) {
            parent = lst_max;
            lst_max = lst_max -> right;
        }
        TreeNode* deleted_node_in_lst;
        // Delete lst_max
        if(is_leaf(lst_max)) {
            deleted_node_in_lst = delete_leaf(lst_max, parent);
        }
        else {      // lst_max has 1 child
            deleted_node_in_lst = delete_single_child(lst_max, parent);
        }
        if(par and par -> left == node) {       // node is a left child of parent
            par -> left = deleted_node_in_lst;
        }
        else if(par and par -> right == node) {          // node is a right child of parent
            par -> right = deleted_node_in_lst;
        }
        deleted_node_in_lst -> left = node -> left;
        deleted_node_in_lst -> right = node -> right;
        return node;
    }
    
    bool has_single_child(TreeNode* node) {
        if(node -> right and node -> left == NULL) {
            return true;
        }
        if(node -> left and node -> right == NULL) {
            return true;
        }
        return false;
    }
    
    TreeNode* delete_root(TreeNode* root) {     // Returning the new root
        if(is_leaf(root)) {
            return NULL;
        }
        if(has_single_child(root)) {
            if(root -> left) {      // Root only has LST    
                return root -> left;
            }
            else {          // Root only has RST
                return root -> right;
            }
        }
        // Root has 2 child
        TreeNode* newRoot = root -> left;
        while(newRoot -> right) {
            newRoot = newRoot -> right;
        }
        TreeNode* node = delete_double_child(root, NULL);
        return newRoot;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        // <Node, par>
        pair<TreeNode*, TreeNode*> p = get_node_and_par(root, key);
        if(p.first == NULL) {       // Node is not found
            return root;
        }
        if(p.first == root) {
            return delete_root(root);
        }
        TreeNode* node;
        if(is_leaf(p.first)) {
            node = delete_leaf(p.first, p.second);
        }
        else if(has_single_child(p.first)) {
            node = delete_single_child(p.first, p.second);
        }
        else {
            node = delete_double_child(p.first, p.second);
        }
        return root;
    }
};