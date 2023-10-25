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
    int helper(TreeNode* root, int&maxSum){
        
        if(!root)   return 0;
        
        int l = helper(root->left, maxSum);
        int r = helper(root->right, maxSum);
        
        // Option1
        int smallAns1 = l + r + root->val;
        
        // Option2
        int smallAns2 = max(l, r) + root->val;
        
        // Option3
        int smallAns3 = root->val;
        
        maxSum = max(maxSum, max(smallAns1, max(smallAns2, smallAns3)));
        
        return max(smallAns2, smallAns3);
        
    }
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        
        helper(root, maxSum);
        
        return maxSum;        
    }
};