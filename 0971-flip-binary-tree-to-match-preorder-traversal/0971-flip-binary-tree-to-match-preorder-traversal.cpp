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
    vector<int>res;
    int i;
    bool preorder(TreeNode* root, vector<int>& voyage){
        
        if(!root)   return true;
        
        if(root->val != voyage[i++])    return false;
        
        if(root->left && root->left->val != voyage[i]){
            res.push_back(root->val);
            return preorder(root->right, voyage) && preorder(root->left, voyage);
        }
        
        return preorder(root->left, voyage) && preorder(root->right, voyage);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        
        res.clear();
        i = 0;
        
        if(!root)   return res;
        
        int idx = 0;
        
        if(preorder(root, voyage) == false)    return {-1};
        
        return res;
    }
};