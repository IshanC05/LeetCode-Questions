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
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode>q = new LinkedList<>();
        q.offer(root);
        
        int res = -1;
        
        while(!q.isEmpty()){
            
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode front = q.poll();
                
                if(front.left != null)     q.offer(front.left);
                if(front.right != null)    q.offer(front.right);
                
                if(i == 0)  res = front.val;
                
            }
        }
        
        return res;        
    }
}