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
    StringBuilder res;
    StringBuilder tempAns;

    public String smallestFromLeaf(TreeNode root) {
        tempAns = new StringBuilder();
        res = new StringBuilder();
        helper(root);
        return res.toString();
    }

    public void helper(TreeNode root){
        if(root == null)    return;

        if(tempAns == null)
            tempAns = new StringBuilder();

        tempAns.append((char)(root.val + 'a'));

        if(root.left == null && root.right == null){
            StringBuilder rev = new StringBuilder(tempAns).reverse();

            if(res.length() == 0 || rev.toString().compareTo(res.toString()) < 0)
                res = rev;
        }

        helper(root.left);
        helper(root.right);

        tempAns.setLength(tempAns.length() - 1);
    }
}