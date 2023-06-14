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
    vector<int>temp;
    void inOrder(TreeNode* root){
        if(!root){
            return;
        }
        inOrder(root->left);
        temp.push_back(root->val);
        inOrder(root->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root){
            return 0;
        }
        inOrder(root);
        int ans = INT_MAX;
        for(int i = 1; i < temp.size(); i++){
            ans = min(ans, temp[i] - temp[i - 1]);
        }
        return ans;
    }
};