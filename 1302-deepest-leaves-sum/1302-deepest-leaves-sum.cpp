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
    int getHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = 1 + getHeight(root->left);
        int right = 1 + getHeight(root->right);
        return max(left, right);
    }
    int getSumAtLevelK(TreeNode* root, int k){
        
        if(!root){
            return 0;
        }
        
        if(k == 1){
            return root->val;
        }
        --k;
        int sum = 0;
        sum += getSumAtLevelK(root->left, k);
        sum += getSumAtLevelK(root->right, k);
        return sum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int k = getHeight(root);
        return getSumAtLevelK(root, k);
    }
};