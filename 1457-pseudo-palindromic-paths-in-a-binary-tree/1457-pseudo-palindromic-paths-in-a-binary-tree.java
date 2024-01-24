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
    private int res;
    public void helper(TreeNode root, int[] freq){
        if(root == null)   return;
        
        ++freq[root.val];
        
        if(root.left == null && root.right == null){
            int totalCount = 0, oddCount = 0;
            
            for(int i = 1; i <= 9; i++){
                if(freq[i] != 0){    
                    ++totalCount;
                    if(freq[i] % 2 != 0)     ++oddCount;
                }
            }
            
            if(oddCount <= 1 && totalCount >= 1)    ++res;
        }
        
        helper(root.left, freq);
        helper(root.right, freq);
        
        --freq[root.val];
    }

    public int pseudoPalindromicPaths (TreeNode root) {
        int[] freq = new int[10];
        res = 0;
        helper(root, freq);
        return res;
    }
}