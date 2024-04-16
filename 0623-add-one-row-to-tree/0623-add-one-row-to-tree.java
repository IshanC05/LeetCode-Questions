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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1){
            TreeNode newRoot = new TreeNode(val);
            newRoot.left = root;
            return newRoot;
        }
        
        int currDepth = 1;
        boolean flag = false;
        
        Queue<TreeNode> q = new ArrayDeque<>();
        q.add(root);
        
        while(!q.isEmpty() && !flag){
            
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode front = q.poll();
             
                if(currDepth == depth - 1){
                    flag = true;
                    
                    TreeNode oldLeftSubTree = null, oldRightSubTree = null;
                    
                    TreeNode newLeftNode = new TreeNode(val);
                    TreeNode newRightNode = new TreeNode(val);
                    
                    if(front.left != null)  oldLeftSubTree = front.left;
                    if(front.right != null)     oldRightSubTree = front.right;
                    
                    front.left = newLeftNode;
                    front.right = newRightNode;
                    
                    newLeftNode.left = oldLeftSubTree;
                    newRightNode.right = oldRightSubTree;
                    
                }else{
                    
                    if(front.left != null)  q.add(front.left);
                    if(front.right != null)     q.add(front.right);
                }
                
            }
        
            ++currDepth;
        }
        
        return root;
    }
}