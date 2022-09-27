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
    
    public void helper(TreeNode root,List<Integer> rightView,int lev) {
        if(root==null) {
            return;
        }
        if(rightView.size()<lev) {
            rightView.add(root.val);
        }
        helper(root.right,rightView,lev+1);
        helper(root.left,rightView,lev+1);
    }
    
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> rightView = new ArrayList<Integer>();
        helper(root,rightView,1);
        return rightView;
    }
}