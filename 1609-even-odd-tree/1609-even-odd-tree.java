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
            
            for(int i = 0; i < qSize; i++){
                TreeNode front = q.poll();
                
                if(front.left != null)  q.offer(front.left);
                if(front.right != null)  q.offer(front.right);
                
                arr[i] = front.val;
            }
            
            if(level % 2 == 0){
                for(int i = 0; i < qSize; i++){
                    if(arr[i] % 2 == 0)     return false;
                    if(i + 1 < qSize){
                        if(arr[i] >= arr[i + 1])    return false;
                    }
                }
            }else{
                for(int i = 0; i < qSize; i++){
                    if(arr[i] % 2 != 0)     return false;
                    if(i + 1 < qSize){
                        if(arr[i] <= arr[i + 1])    return false;
                    }                    
                }
            }
            
            ++level;            
        }
        
        return true;
    }
}