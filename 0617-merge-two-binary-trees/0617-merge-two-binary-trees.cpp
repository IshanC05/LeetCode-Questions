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
    TreeNode* helper(TreeNode* p, TreeNode* q){
        
        if(!p && !q)    return NULL;
        
        if(!p)      return q;
        
        if(!q)      return p;
        
        int rootVal = (p->val + q->val); 
        
        TreeNode* root = new TreeNode(rootVal);
        
        root->left = helper(p->left, q->left);
        
        root->right = helper(p->right, q->right);
        
        return root;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return helper(root1, root2);
    }
};