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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode>q = new LinkedList<>();
        q.offer(root);
        
        int level = 0;
        
        while(!q.isEmpty()){
            int qSize = q.size();
            int arr[] = new int[qSize];
            int prev = ((level % 2 == 0) ? 0 : Integer.MAX_VALUE);
            
            for(int i = 0; i < qSize; i++){
                TreeNode front = q.poll();
                
                if(front.left != null)  q.offer(front.left);
                if(front.right != null)  q.offer(front.right);
                
                int curr = front.val;
                
                if(level % 2 == 0){
                    if(curr % 2 == 0)   return false;
                    if(prev != 0){
                        if(prev >= curr)    return false;
                    }
                }else{
                    if(curr % 2 != 0)     return false;
                    if(prev != Integer.MAX_VALUE){
                        if(prev <= curr)    return false;
                    } 
                }
                
                prev = curr;
            }
            
            ++level;            
        }
        
        return true;
    }
}