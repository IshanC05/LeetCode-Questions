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
    int getHeight(TreeNode* root, bool &res){
        
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int l = getHeight(root->left, res);
        int r = getHeight(root->right, res);
        
        if(abs(l - r) > 1)
            res = false;
        
        return 1 + max(l, r);        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(!root)   
            return true;
        
        bool res = true;
        
        getHeight(root, res);
        
        return res;
    }
};