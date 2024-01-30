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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double>res = new ArrayList<>();
        
        Queue<TreeNode>q = new LinkedList<>();
        q.add(root);
        
        while(!q.isEmpty()){
            
            long qSize = q.size(), sum = 0;
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode front = q.remove();
                
                if(front.left != null)     q.add(front.left);
                if(front.right != null)    q.add(front.right);
                
                sum += front.val;
            }
            
            res.add((double)sum / qSize);            
        }
        
        return res; 
    }
}