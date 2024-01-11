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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }

    int dfs(TreeNode* root, int min_val, int max_val) {
        if (!root) return max_val - min_val;

        min_val = min(min_val, root->val);
        max_val = max(max_val, root->val);

        int left_diff = dfs(root->left, min_val, max_val);
        int right_diff = dfs(root->right, min_val, max_val);

        return max(left_diff, right_diff);
    }
};