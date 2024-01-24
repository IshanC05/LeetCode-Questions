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
    void helper(TreeNode* root, vector<int>&freq, int&res){
        if(!root)   return;
        
        ++freq[root->val];
        
        if(!root->left && !root->right){
            int totalCount = 0, oddCount = 0;
            
            for(int i = 1; i <= 9; i++){
                if(freq[i] != 0){    
                    ++totalCount;
                    if(freq[i] & 1)     ++oddCount;
                }
            }
            
            if(oddCount <= 1 && totalCount >= 1)    ++res;
        }
        
        helper(root->left, freq, res);
        helper(root->right, freq, res);
        
        --freq[root->val];
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>freq(10, 0);
        int res = 0;
        helper(root, freq, res);
        return res;
    }
};