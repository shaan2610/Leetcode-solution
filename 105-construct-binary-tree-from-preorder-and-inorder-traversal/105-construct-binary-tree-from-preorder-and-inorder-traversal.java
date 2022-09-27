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
    
    TreeNode helper(int[] preorder, int sp, int ep, int[] inorder, int si, int ei) {
        if(sp>ep || si>ei) {
            return null;
        }
        TreeNode node=new TreeNode(preorder[sp]);
        int inLeft=si;
        while(inorder[inLeft]!=preorder[sp]) {
            inLeft++;
        }
        int sz=inLeft-si;
        node.left=helper(preorder,sp+1,sp+1+sz-1,inorder,si,inLeft-1);
        node.right=helper(preorder,sp+1+sz,ep,inorder,inLeft+1,ei);
        return node;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n=preorder.length;
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
}