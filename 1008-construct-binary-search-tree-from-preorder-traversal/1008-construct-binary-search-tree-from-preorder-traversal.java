/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public int idx=0;
    
    public TreeNode helper(int[] preorder,int upperBound) {
        int n=preorder.length;
        if(idx>=n || preorder[idx]>=upperBound) {
            return null;
        }
        TreeNode node=new TreeNode(preorder[idx++]);
        node.left=helper(preorder,node.val);
        node.right=helper(preorder,upperBound);
        return node;
    }
    
    public TreeNode bstFromPreorder(int[] preorder) {
        int n=preorder.length;
        return helper(preorder,1005);
    }
}