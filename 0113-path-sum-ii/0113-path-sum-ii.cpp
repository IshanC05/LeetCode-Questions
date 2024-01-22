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
    vector<vector<int>> res;
    void helper(TreeNode* root, int sum, vector<int>& t) {
        if (!root)
            return;

        t.push_back(root->val);

        if (sum == root->val && !root->left && !root->right) {
            res.push_back(t);
        }

        helper(root->left, sum - root->val, t);
        helper(root->right, sum - root->val, t);

        t.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        vector<int> input;
        helper(root, sum, input);
        return res;   
    }
};