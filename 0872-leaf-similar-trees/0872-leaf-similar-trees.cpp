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
    void getLeafs(TreeNode* root, vector<int>&list){
        if(!root)   return;
        
        if(!root->left && !root->right){
            list.push_back(root->val);
            return;
        }
        
        getLeafs(root->left, list);
        getLeafs(root->right, list);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seq1, seq2;
        
        getLeafs(root1, seq1);
        getLeafs(root2, seq2);
        
        if(seq1.size() != seq2.size())  return false;
        
        for(int i = 0; i < seq1.size(); i++)
            if(seq1[i] != seq2[i])  return false;
        
        return true;
    }
};