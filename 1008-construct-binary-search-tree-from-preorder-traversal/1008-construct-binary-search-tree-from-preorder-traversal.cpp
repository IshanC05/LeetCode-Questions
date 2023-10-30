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
    TreeNode* helper(vector<int>& arr, int &i, int n, int bound){
        
        if(i >= n || arr[i] > bound)  return NULL;
        
        TreeNode* root = new TreeNode(arr[i++]);
        
        root->left = helper(arr, i, n, root->val);
        
        root->right = helper(arr, i, n, bound);
        
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        int i = 0, n = preorder.size();
        
        return helper(preorder, i, n, INT_MAX);        
    }
};