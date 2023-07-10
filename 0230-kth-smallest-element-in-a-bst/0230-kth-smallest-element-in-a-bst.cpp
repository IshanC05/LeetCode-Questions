/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    priority_queue<int, vector<int>, greater<int>>pq;
    
    void getAllNodes(TreeNode* root){
        
        if(!root)   return;
        
        pq.push(root->val);
        
        getAllNodes(root->left);
        
        getAllNodes(root->right);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        getAllNodes(root);
        
        int ans;
        
        while(k--){
            
            ans = pq.top();
            
            pq.pop();
            
        }
        
        return ans;
        
    }
};