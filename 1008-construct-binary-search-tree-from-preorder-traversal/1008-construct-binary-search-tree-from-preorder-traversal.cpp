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
    TreeNode* insertANode(TreeNode* root, int key){
     
        if(!root)   return new TreeNode(key);
        
        if(root->val > key){
            root->left = insertANode(root->left, key);
        }
        
        else    root->right = insertANode(root->right, key);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < preorder.size(); i++){
            
            root = insertANode(root, preorder[i]);
            
        }
        
        return root;        
    }
};