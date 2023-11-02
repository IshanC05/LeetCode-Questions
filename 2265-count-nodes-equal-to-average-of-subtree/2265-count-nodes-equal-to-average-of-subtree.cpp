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
    // <numNodes, sum>
    pair<int,int> helper(TreeNode* root, int& n){
        
        if(!root)   return {0, 0};
        
        if(!root->left && !root->right){
            ++n;
            return {1, root->val};
        }
        
        pair<int, int>left, right;
        
        left = helper(root->left, n);
        
        right = helper(root->right, n);
        
        int totalNodes = 1 + left.first + right.first;
        
        int totalSum = root->val + left.second + right.second;
        
        if(totalSum / totalNodes == root->val)  ++n;
        
        return {totalNodes, totalSum};
        
    }
    int averageOfSubtree(TreeNode* root) {
        
        int n = 0;
        
        helper(root, n);
        
        return n;        
    }
};