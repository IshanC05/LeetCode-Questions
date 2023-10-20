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
    bool contains1(TreeNode* root){
        
        if(!root)     return false;
        
        if(root->val == 1)      return true;
        
        return (contains1(root->left) || contains1(root->right));
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root)   return root;
        
        if(!contains1(root))    return nullptr;
        
        root->left = pruneTree(root->left);
        
        root->right = pruneTree(root->right);
        
        return root;
    }
};