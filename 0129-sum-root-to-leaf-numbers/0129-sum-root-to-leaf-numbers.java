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
    int res;
    List<Integer> arr;
    
    public void helper(TreeNode root){
        if(root == null)    return;
        
        arr.add(root.val);
        
        if(root.left == null && root.right == null){
            int tempAns = 0;
            
            for(Integer i : arr)    tempAns = tempAns * 10 + i;
                
            res += tempAns;
        }
        
        if(root.left != null)   helper(root.left);
        
        if(root.right != null)   helper(root.right);
        
        arr.remove(arr.size() - 1);
    }
    
    public int sumNumbers(TreeNode root) {
        res = 0;
        arr = new ArrayList<>();
        helper(root);
        return res;
    }
}