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
    void preorder(TreeNode root, StringBuilder res){
        
        if(root == null)    return;
        
        boolean isLeaf = (root.left == null && root.right == null) ? true : false;
        
        res.append("(");
        
        res.append(root.val);
        
        if(!isLeaf){
            
            if(root.left != null)  preorder(root.left, res);
            
            else    res.append("()");
            
            preorder(root.right, res);            
            
        }
        
        res.append(")");
        
    }
    
    public String tree2str(TreeNode root) {
        
        if(root == null)    return new String("");
        
        StringBuilder res = new StringBuilder();
        
        preorder(root, res);
        
        return res.substring(1, res.length() - 1);        
    }
}