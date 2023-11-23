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
    vector<TreeNode*>candidates;
    void findSubRoot(TreeNode* root, TreeNode* t){
        
        if(!root)   return;
        
        if(root->val == t->val){
            candidates.push_back(root);
        }
        
        findSubRoot(root->left, t);
        
        findSubRoot(root->right, t);        
    }
    
    bool isSame(TreeNode* r1, TreeNode* r2){
        
        if(!r1 && !r2)  return true;
        
        if((!r1 || !r2) || (r1->val != r2->val))  return false;
        
        return isSame(r1->left, r2->left) && isSame(r1->right, r2->right);        
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!subRoot)    return true;
        
        candidates.clear();
        
        findSubRoot(root, subRoot);
        
        bool res = false;
        
        for(auto it : candidates){
            
            res = isSame(it, subRoot);
            
            if(res)     break;
            
        }
        
        return res;
    }
};