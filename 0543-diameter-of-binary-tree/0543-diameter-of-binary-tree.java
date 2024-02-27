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
    public int res;
    public int getHeight(TreeNode root){
        if(root == null)    return 0;
        
        int l = getHeight(root.left);
        int r = getHeight(root.right);
        
        res = Math.max(res, l + r);
        return 1 + Math.max(l, r);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        res = 0;
        getHeight(root);
        return res;
    }
}