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
    int count;
    
    void helper(TreeNode* root, int maxSoFar){
        
        if(!root)
            return;
        
        if(maxSoFar <= root->val)   ++count;
        
        maxSoFar = max(maxSoFar, root->val);
        
        helper(root->left, maxSoFar);
        
        helper(root->right, maxSoFar);
    }
    
    int goodNodes(TreeNode* root) {
        
        count = 0;
        
        if(!root)
            return count;
        
        int maxSoFar = root->val;
        
        helper(root, maxSoFar);
        
        return count;
    }
};