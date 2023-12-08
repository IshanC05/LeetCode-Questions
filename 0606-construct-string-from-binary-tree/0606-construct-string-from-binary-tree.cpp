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
    void preorder(TreeNode* root, string&res){
        
        if(!root)   return;
        
        bool isLeaf = (!root->left && !root->right) ? true : false;
        
        res.push_back('(');
        
        res.append(to_string(root->val));
        
        if(!isLeaf){
            
            if(root->left)  preorder(root->left, res);

            else    res.append("()");

            if(root->right)     preorder(root->right, res);   
            
        }
        
        res.push_back(')');
    }
    string tree2str(TreeNode* root) {
        
        if(!root)   return "";
        
        string res = "";
        
        preorder(root, res);
        
        return res.substr(1, res.size() - 2);        
    }
};