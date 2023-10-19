/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* x, vector<TreeNode*>&res){
        if(!root)	return false;

        if(root->val == x->val){
            res.push_back(root);
            return true;
        }

        bool left = getPath(root->left, x, res);
        bool right = getPath(root->right, x, res);

        if(left || right){
            res.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP, pathQ;
        
        getPath(root, p, pathP);
        getPath(root, q, pathQ);
        
        int i = pathP.size() - 1, j = pathQ.size() - 1;
        
        TreeNode* res = root;
        
        while(i >= 0 && j >= 0){
            
            if(pathP[i] == pathQ[j])    res = pathP[i];
            
            else    break;
            
            --i;
            --j;
        }
        
        return res;
    }
};